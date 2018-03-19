#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>

#include <moca_os.h>
#include <mocalib.h>
#include <moca_os.h>
#include "GCAP_Common.h"

static char *chipId = NULL;    // -i option
int interval = 0;
int duration = 0;
int endless = 0;
int g_active_nodes = 0;


static macaddr_t nodemacs[16];

GCAP_GEN static void showUsage()
{
    printf("Usage: GCAP.17 [-i <polling interval>] [-t <polling duration>] [-h]\n\
Report time-stamps whenever nodes join in or drop out .\n\
\n\
Options:\n\
  -i   Set polling interval in number of seconds (default 1 second)\n\
  -t   Set polling duration in number of minutes (default forever until\n\
       Ctrl-C to break)\n\
  -e   Allow polling to continue if link goes down (default polling\n\
       stops when MoCA link goes down)\n\
  -h   Display this help and exit\n");
}

GCAP_GEN static void callback(void *userarg, uint32_t active_nodes)
{
#ifndef STANDALONE
    time_t t;
    struct tm *timex;
#endif
    struct moca_gen_node_status nodestatus;
    int ret;
    void *ctx = userarg;
    int nodeid;
    int joined;
    macaddr_t   mac;

    memset (&mac, 0, sizeof(mac));
    for (nodeid = 0; nodeid < MOCA_MAX_NODES; nodeid++)
    {
        if ((g_active_nodes & (1 << nodeid)) !=
            (active_nodes & (1 << nodeid)))
        {           
            joined = (active_nodes >> nodeid) & 0x1;        
        
            if (joined)
            {
               do 
               {
                   MoCAOS_MSleep(20);
                   ret = moca_get_gen_node_status(ctx, nodeid, &nodestatus);
                   if (ret != MOCA_API_SUCCESS)
                   {
                       printf( "Error!  Internal failure 2\n");
                       moca_cancel_event_loop(userarg);
                       return;
                   }
                } while (memcmp(&mac, &nodestatus.eui, sizeof(macaddr_t)) == 0);

                memcpy(&nodemacs[nodeid], &nodestatus.eui, sizeof(macaddr_t));
            }
#ifndef STANDALONE
            t=time(NULL);
            timex=localtime(&t);

            printf("%02d:%02d:%02d Node %2d [%02x:%02x:%02x:%02x:%02x:%02x] %s\n", 
                timex->tm_hour, timex->tm_min, timex->tm_sec, nodeid,
                MOCA_DISPLAY_MAC(nodemacs[nodeid]),
                joined?"JOINED":"DROPPED");
#else
            printf("Node %2d [%02x:%02x:%02x:%02x:%02x:%02x] %s\n", nodeid,
                    MOCA_DISPLAY_MAC(nodemacs[nodeid]), joined?"JOINED":"DROPPED");
#endif
        }
    }
    g_active_nodes = active_nodes;
}


GCAP_GEN static void link_cb(void * userarg, uint32_t status)
{
    if (status == 0)
    {
        printf("Error! No Link\n");
        moca_cancel_event_loop(userarg);
    }
}

GCAP_GEN int GCAP_17_main(int argc, char **argv)
{
  
    int ret = MOCA_API_SUCCESS;
    struct moca_interface_status status;
    struct moca_network_status nws;
    struct moca_gen_node_status nodestatus;
    int i;
    void *ctx;

    chipId = NULL;

#ifdef STANDALONE
   for (i=1; i < argc; i++)
   {
        if (strcmp(argv[i], "-x") == 0)
        {
           i++;
           chipId = argv[i];
        }
        else if (strcmp(argv[i], "-i") == 0)
        {
           interval = atoi(argv[i+1]);
           i++;
        }
        else if (strcmp(argv[i], "-t") == 0)
        {
           duration = atoi(argv[i+1]);
           i++;
        }

        else if (strcmp(argv[i], "-e") == 0)
        {
           endless = 1; 
        }
        else if (strcmp(argv[i], "?") == 0)
        {
           printf( "Error!  Invalid option - %s\n", argv[i]);
           return(-1);
        }
        else if (strcmp(argv[i], "-h") == 0)
        {
           showUsage();
           return(0); 
        }
   }
#else
    time_t t;
    struct tm *timex;    
   

    moca_gcap_init();

    // ----------- Parse parameters
    
    opterr = 0;
    
    while((ret = getopt(argc, argv, "hex:i:t:")) != -1) 
    {
        switch(ret)
        {
        case 'e':
            endless = 1;
            break;
        case 'x':
            chipId = optarg;
            break;            
        case 'i':
            interval = atoi(optarg);
            break;
        case 't':
            duration = atoi(optarg);
            break;
        case '?':
            printf( "Error!  Invalid option - %c\n", optopt);
            return(-1);
            break;
        case 'h':
        default:
            showUsage();
            return(0); 
        }
    }

    // ----------- Initialize
#endif
    ctx = moca_open(chipId);

    if (!ctx)
    {
        printf( "Error!  Unable to connect to moca instance\n");
        return(-2);
    }

    // ----------- Get info
    ret = moca_get_interface_status(ctx, &status);

    if (ret != MOCA_API_SUCCESS)
    {
        printf( "Error!  Internal failure\n");
        moca_close(ctx);
        return(-3);
    }

    if (status.link_status != MOCA_LINK_UP)
    {
        printf( "Error! No Link\n");
        moca_close(ctx);
        return(-4);
    }  

    ret = moca_get_network_status(ctx, &nws);

    if (ret != MOCA_API_SUCCESS)
    {
        printf( "Error!  Internal failure\n");
        moca_close(ctx);
        return(-5);
    }

    
    g_active_nodes = nws.connected_nodes;
    
#ifndef STANDALONE

    t=time(NULL);
    timex=localtime(&t);
    
    printf("%02d:%02d:%02d Moca Monitoring STARTED.\n", 
      timex->tm_hour, timex->tm_min, timex->tm_sec);
#endif

    moca_register_topology_changed_cb(ctx, callback, ctx);

    if (endless == 0)
       moca_register_link_up_state_cb(ctx, link_cb, ctx);

    // read in the mac addresses so we remember them when a node drops off
    for (i = 0; i < MOCA_MAX_NODES; i++)
    {
        ret = moca_get_gen_node_status(ctx, i, &nodestatus);

        if (ret != MOCA_API_SUCCESS)
        {
            printf( "Error!  Internal failure 2\n");
            moca_close(ctx);
            return(-6);
        }
        memcpy(&nodemacs[i], &nodestatus.eui, sizeof(macaddr_t));
    }

    if (duration)
        MoCAOS_Alarm(duration*60);

    moca_event_loop(ctx);


    // ----------- Finish

    moca_close(ctx);
    return(0);
}

