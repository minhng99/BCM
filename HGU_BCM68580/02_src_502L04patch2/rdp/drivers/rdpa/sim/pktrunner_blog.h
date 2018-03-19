#ifndef __BLOG_H_INCLUDED__
#define __BLOG_H_INCLUDED__

/*-----------------------------------------*/
/* Blog.h FOR PYTHON PKTRUNNER EXTENSION   */
/*-----------------------------------------*/

/* 
* <:copyright-BRCM:2003:DUAL/GPL:standard
* 
*    Copyright (c) 2003 Broadcom 
*    All Rights Reserved
* 
* Unless you and Broadcom execute a separate written software license
* agreement governing use of this software, this software is licensed
* to you under the terms of the GNU General Public License version 2
* (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
* with the following added to such license:
* 
*    As a special exception, the copyright holders of this software give
*    you permission to link this software with independent modules, and
*    to copy and distribute the resulting executable under terms of your
*    choice, provided that you also meet, for each linked independent
*    module, the terms and conditions of the license of that module.
*    An independent module is a module which is not derived from this
*    software.  The special exception does not apply to any modifications
*    of the software.
* 
* Not withstanding the above, under no circumstances may you combine
* this software in any way with any other Broadcom software provided
* under a license other than the GPL, without Broadcom's express prior
* written consent.
* 
:>
*/

/*
 *******************************************************************************
 *
 * File Name  : pktrnr_blog.h
 *
 * Description:
 *
 * This is a smaller copy of the file found in comengine/kernel...
 * It contains only the necessary fields to run PktRunner.
 * If it fails compilation it is because PktRunner is now
 * using new fields from Blog.h.  Modify this file and add
 * the new fields.
 *
 *******************************************************************************
 */

#define BLOG_VERSION            "v3.0"

#include "pktrunner_blog_rule.h"

extern const uint8_t    rfc2684HdrLength[];

#define BLOG_DECL(x) x,
#define BLOG_NULL                   ((Blog_t*)NULL)


/*
 *------------------------------------------------------------------------------
 * RFC 2684 header logging.
 * CAUTION: 0'th enum corresponds to either header was stripped or zero length
 *          header. VC_MUX_PPPOA and VC_MUX_IPOA have 0 length RFC2684 header.
 *          PTM does not have an rfc2684 header.
 *------------------------------------------------------------------------------
 */
typedef enum {
        BLOG_DECL(RFC2684_NONE)         /*                               */
        BLOG_DECL(LLC_SNAP_ETHERNET)    /* AA AA 03 00 80 C2 00 07 00 00 */
        BLOG_DECL(LLC_SNAP_ROUTE_IP)    /* AA AA 03 00 00 00 08 00       */
        BLOG_DECL(LLC_ENCAPS_PPP)       /* FE FE 03 CF                   */
        BLOG_DECL(VC_MUX_ETHERNET)      /* 00 00                         */
        BLOG_DECL(VC_MUX_IPOA)          /*                               */
        BLOG_DECL(VC_MUX_PPPOA)         /*                               */
        BLOG_DECL(PTM)                  /*                               */
        BLOG_DECL(RFC2684_MAX)
} Rfc2684_t;


/*
 *------------------------------------------------------------------------------
 * Denotes the type of physical interface and the presence of a preamble.
 *------------------------------------------------------------------------------
 */
typedef enum {
    BLOG_DECL(BLOG_XTMPHY)
    BLOG_DECL(BLOG_ENETPHY)
    BLOG_DECL(BLOG_GPONPHY)
    BLOG_DECL(BLOG_EPONPHY)
    BLOG_DECL(BLOG_USBPHY)
    BLOG_DECL(BLOG_WLANPHY)
    BLOG_DECL(BLOG_MOCAPHY)
    BLOG_DECL(BLOG_EXTRA1PHY)
    BLOG_DECL(BLOG_EXTRA2PHY)
    BLOG_DECL(BLOG_EXTRA3PHY)
    BLOG_DECL(BLOG_LTEPHY)
    BLOG_DECL(BLOG_SIDPHY)
    BLOG_DECL(BLOG_TCP4_LOCALPHY)
    BLOG_DECL(BLOG_SPU_DS)
    BLOG_DECL(BLOG_SPU_US)
    BLOG_DECL(BLOG_MAXPHY)
} BlogPhy_t;

/* CAUTION: Following macros have binary dependencies. Please do not change these
   macros without consulting with Broadcom or the subsystem owners
   Macro definition START */
#define BLOG_IS_HWACC_DISABLED_WLAN_EXTRAPHY(rxphy,txphy) ((rxphy == BLOG_EXTRA1PHY) || \
                                                           (rxphy == BLOG_EXTRA2PHY) || \
                                                           (rxphy == BLOG_EXTRA3PHY) || \
                                                           (txphy == BLOG_EXTRA1PHY) || \
                                                           (txphy == BLOG_EXTRA2PHY) || \
                                                           (txphy == BLOG_EXTRA3PHY))
#define BLOG_IS_TX_HWACC_ENABLED_WLAN_PHY(txphy) (txphy == BLOG_WLANPHY)
/* Macro definition END */

/*
 *------------------------------------------------------------------------------
 * Logging of a maximum 4 "virtual" network devices that a flow can traverse.
 * Virtual devices are interfaces that do not perform the actual DMA transfer.
 * E.g. an ATM interface would be referred to as a physical interface whereas
 * a ppp interface would be referred to as a Virtual interface.
 *------------------------------------------------------------------------------
 */
#define MAX_VIRT_DEV           7

#define DEV_DIR_MASK           0x3ul
#define DEV_PTR_MASK           (~DEV_DIR_MASK)
#define DEV_DIR(ptr)           ((uintptr_t)(ptr) & DEV_DIR_MASK)

#define IS_RX_DIR(ptr)         ( DEV_DIR(ptr) == DIR_RX )
#define IS_TX_DIR(ptr)         ( DEV_DIR(ptr) == DIR_TX )

/*
 *------------------------------------------------------------------------------
 * Device pointer conversion between with and without embeded direction info
 *------------------------------------------------------------------------------
 */
#define DEVP_APPEND_DIR(ptr,dir) ((void *)((uintptr_t)(ptr) | (uintptr_t)(dir)))
#define DEVP_DETACH_DIR(ptr)     ((void *)((uintptr_t)(ptr) & (uintptr_t) \
                                                              DEV_PTR_MASK))
/*
 *------------------------------------------------------------------------------
 * Denotes the tos mode.
 *------------------------------------------------------------------------------
 */
typedef enum {
    BLOG_DECL(BLOG_TOS_FIXED)
    BLOG_DECL(BLOG_TOS_INHERIT)
    BLOG_DECL(BLOG_TOS_MAX)
} BlogTos_t;


/*
 * -----------------------------------------------------------------------------
 * Support accleration of L2, L3 packets.
 *
 * When acceleration support is enabled system wide, the default to be used may
 * be set in CC_BLOG_SUPPORT_ACCEL_MODE which gets saved in blog_support_accel_mode_g.
 * One may change the default (at runtime) by invoking blog_support_accel_mode().
 * -----------------------------------------------------------------------------
 */


/* Traffic type */
typedef enum {
    BLOG_DECL(BlogTraffic_IPV4_UCAST)
    BLOG_DECL(BlogTraffic_IPV6_UCAST)
    BLOG_DECL(BlogTraffic_IPV4_MCAST)
    BLOG_DECL(BlogTraffic_IPV6_MCAST)
    BLOG_DECL(BlogTraffic_Layer2_Flow)
    BLOG_DECL(BlogTraffic_MAX)
} BlogTraffic_t;


#define BLOG_SET_PHYHDR(a, b)   ( (((a) & 0xf) << 4) | ((b) & 0xf) )
#define BLOG_GET_PHYTYPE(a)     ( (a) & 0xf )
#define BLOG_GET_PHYLEN(a)      ( (a) >> 4 )

#define BLOG_PHYHDR_MASK        0xff
#define BLOG_SET_HW_ACT(a)      ( ((a) & 0xf) << 8 )
#define BLOG_GET_HW_ACT(a)      ( (a) >> 8 )



/*
 * -----------------------------------------------------------------------------
 *                      Section: Definition of a Blog_t
 * -----------------------------------------------------------------------------
 */

#define BLOG_CHAN_INVALID   0xFF


typedef struct {
    uint16_t         GRE_ETH     : 1;    /* Ethernet over GRE */
    uint16_t         BCM_XPHY    : 1;    /* e.g. BCM_XTM */
    uint16_t         BCM_SWC     : 1;
    uint16_t         ETH_802x    : 1;
    uint16_t         VLAN_8021Q  : 1;    
    uint16_t         PPPoE_2516  : 1;
    uint16_t         PPP_1661    : 1;
    uint16_t         PLD_IPv4    : 1;
    uint16_t         PLD_IPv6    : 1;
    uint16_t         PPTP        : 1;
    uint16_t         L2TP        : 1;
    uint16_t         GRE         : 1;
    uint16_t         ESP         : 1; 
    uint16_t         DEL_IPv4    : 1;
    uint16_t         DEL_IPv6    : 1;
    uint16_t         PLD_L2      : 1;
} Blog_Info_Bmap_t;/* as per order of BlogEncap_t enums declaration */


typedef struct {
    uint8_t         channel;        /* e.g. port number, txchannel, ... */

    union {
        struct {
            uint8_t         phyHdrLen   : 4;
            uint8_t         phyHdrType  : 4;
        };
        uint8_t             phyHdr;
    };

    union {
        Blog_Info_Bmap_t    bmap;
        uint16_t            hdrs;
    };

} BlogInfo_t;

/*
 *------------------------------------------------------------------------------
 * Buffer to log IP Tuple.
 * Packed: 1 16byte cacheline.
 *------------------------------------------------------------------------------
 */
typedef struct {
    uint16_t   source;
    uint16_t   dest;
} ports_t;
 

struct blogTuple_t {
    uint32_t        saddr;          /* IP header saddr */
    uint32_t        daddr;          /* IP header daddr */

    union {
        ports_t     port;
        uint32_t    ports;
    };

    uint8_t         ttl;            /* IP header ttl */
    uint8_t         tos;            /* IP header tos */
    uint16_t        check;          /* checksum: rx tuple=l3, tx tuple=l4 */

};
typedef struct blogTuple_t BlogTuple_t;





#define NEXTHDR_IPV4 IPPROTO_IPIP

#define HDRS_IPinIP     ((1<<GRE) | (1<<ESP) | (1<<PLD_IPv4) | (1<<PLD_IPv6) |    \
                         (1<<DEL_IPv4) | (1<<DEL_IPv6))
#define HDRS_IP4in4     ((1<<PLD_IPv4) | (1<<DEL_IPv4))
#define HDRS_IP6in4     ((1<<PLD_IPv6) | (1<<DEL_IPv4))
#define HDRS_IP4in6     ((1<<PLD_IPv4) | (1<<DEL_IPv6))
#define HDRS_GIP4       ((1<<PLD_IPv4) | (1<<GRE))
#define HDRS_EIP4       ((1<<PLD_IPv4) | (1<<ESP))

#define RX_IP4in6(b)    (((b)->rx.info.hdrs & HDRS_IPinIP)==HDRS_IP4in6)
#define RX_IP6in4(b)    (((b)->rx.info.hdrs & HDRS_IPinIP)==HDRS_IP6in4)
#define TX_IP4in6(b)    (((b)->tx.info.hdrs & HDRS_IPinIP)==HDRS_IP4in6)
#define TX_IP6in4(b)    (((b)->tx.info.hdrs & HDRS_IPinIP)==HDRS_IP6in4)

#define RX_IPV4(b)      ((b)->rx.info.bmap.PLD_IPv4)
#define TX_IPV4(b)      ((b)->tx.info.bmap.PLD_IPv4)
#define RX_IPV6(b)      ((b)->rx.info.bmap.PLD_IPv6)
#define TX_IPV6(b)      ((b)->tx.info.bmap.PLD_IPv6)
#define RX_IPV4_DEL(b)  ((b)->rx.info.bmap.DEL_IPv4)
#define TX_IPV4_DEL(b)  ((b)->tx.info.bmap.DEL_IPv4)
#define RX_IPV6_DEL(b)  ((b)->rx.info.bmap.DEL_IPv6)
#define TX_IPV6_DEL(b)  ((b)->tx.info.bmap.DEL_IPv6)

#define RX_GRE(b)       ((b)->rx.info.bmap.GRE)
#define TX_GRE(b)       ((b)->tx.info.bmap.GRE)
#define RX_ESP(b)       ((b)->rx.info.bmap.ESP)
#define TX_ESP(b)       ((b)->tx.info.bmap.ESP)

#define RX_IPV4ONLY(b)  (((b)->rx.info.hdrs & HDRS_IPinIP)==(1 << PLD_IPv4))
#define TX_IPV4ONLY(b)  (((b)->tx.info.hdrs & HDRS_IPinIP)==(1 << PLD_IPv4))
#define RX_IPV6ONLY(b)  (((b)->rx.info.hdrs & HDRS_IPinIP)==(1 << PLD_IPv6))
#define TX_IPV6ONLY(b)  (((b)->tx.info.hdrs & HDRS_IPinIP)==(1 << PLD_IPv6))

#define RX_IPV4_OUTER(b) (RX_IPV4ONLY(b) || RX_IPV4_DEL(b))
#define TX_IPV4_OUTER(b) (TX_IPV4ONLY(b) || TX_IPV4_DEL(b))
#define RX_IPV6_OUTER(b) (RX_IPV6ONLY(b) || RX_IPV6_DEL(b))
#define TX_IPV6_OUTER(b) (TX_IPV6ONLY(b) || TX_IPV6_DEL(b))

#define MAPT_UP(b)      (RX_IPV4ONLY(b) && TX_IPV6ONLY(b))
#define MAPT_DN(b)      (RX_IPV6ONLY(b) && TX_IPV4ONLY(b))
#define MAPT(b)         (MAPT_DN(b) || MAPT_UP(b))

#define HDRS_IPV4       ((1 << PLD_IPv4) | (1 << DEL_IPv4))
#define HDRS_IPV6       ((1 << PLD_IPv6) | (1 << DEL_IPv6))

#define T4in6UP(b)      (RX_IPV4ONLY(b) && TX_IP4in6(b))
#define T4in6DN(b)      (RX_IP4in6(b) && TX_IPV4ONLY(b))

#define T6in4UP(b)      (RX_IPV6ONLY(b) && TX_IP6in4(b))
#define T6in4DN(b)      (RX_IP6in4(b) && TX_IPV6ONLY(b))

#define CHK4in6(b)      (T4in6UP(b) || T4in6DN(b))
#define CHK6in4(b)      (T6in4UP(b) || T6in4DN(b)) 
#define CHK4to4(b)      (RX_IPV4ONLY(b) && TX_IPV4ONLY(b))
#define CHK6to6(b)      (RX_IPV6ONLY(b) && TX_IPV6ONLY(b))

#define HDRS_GIP4in4    ((1<<GRE) | HDRS_IP4in4)
#define HDRS_GIP6in4    ((1<<GRE) | HDRS_IP6in4)

#define RX_GIPV4ONLY(b)  (((b)->rx.info.hdrs & HDRS_IPinIP)== HDRS_GIP4)
#define TX_GIPV4ONLY(b)  (((b)->tx.info.hdrs & HDRS_IPinIP)== HDRS_GIP4)

#define RX_GIP4in4(b)   (((b)->rx.info.hdrs & HDRS_IPinIP)==HDRS_GIP4in4)
#define TX_GIP4in4(b)   (((b)->tx.info.hdrs & HDRS_IPinIP)==HDRS_GIP4in4)
#define RX_GIP6in4(b)   (((b)->rx.info.hdrs & HDRS_IPinIP)==HDRS_GIP6in4)
#define TX_GIP6in4(b)   (((b)->tx.info.hdrs & HDRS_IPinIP)==HDRS_GIP6in4)
#define RX_GIP46in4(b)  (RX_GIP4in4(b) || RX_GIP6in4(b))
#define TX_GIP46in4(b)  (TX_GIP4in4(b) || TX_GIP6in4(b))

#define TG4in4UP(b)     (RX_IPV4ONLY(b) && TX_GIP4in4(b))
#define TG4in4DN(b)     (RX_GIP4in4(b) && TX_IPV4ONLY(b))
#define TG6in4UP(b)     (RX_IPV6ONLY(b) && TX_GIP6in4(b))
#define TG6in4DN(b)     (RX_GIP6in4(b) && TX_IPV6ONLY(b))

#define CHKG4in4(b)     (TG4in4UP(b) || TG4in4DN(b))
#define CHKG6in4(b)     (TG6in4UP(b) || TG6in4DN(b))
#define CHKG46in4UP(b)  (TG4in4UP(b) || TG6in4UP(b))
#define CHKG46in4DN(b)  (TG4in4DN(b) || TG6in4DN(b))
#define CHKG46in4(b)    (CHKG4in4(b) || CHKG6in4(b))

#define PTE4(b)         (RX_EIPV4ONLY(b) && TX_EIPV4ONLY(b))
#define PTG4(b)         (RX_GIPV4ONLY(b) && TX_GIPV4ONLY(b))

#define HDRS_EIP4in4    ((1<<ESP) | HDRS_IP4in4)
#define HDRS_EIP6in4    ((1<<ESP) | HDRS_IP6in4)

#define RX_EIP4in4(b)   (((b)->rx.info.hdrs & HDRS_IPinIP)==HDRS_EIP4in4)
#define TX_EIP4in4(b)   (((b)->tx.info.hdrs & HDRS_IPinIP)==HDRS_EIP4in4)
#define RX_EIP6in4(b)   (((b)->rx.info.hdrs & HDRS_IPinIP)==HDRS_EIP6in4)
#define TX_EIP6in4(b)   (((b)->tx.info.hdrs & HDRS_IPinIP)==HDRS_EIP6in4)

#define TE4in4UP(b)     (RX_IPV4ONLY(b) && TX_EIP4in4(b))
#define TE4in4DN(b)     (RX_EIP4in4(b) && TX_IPV4ONLY(b))
#define TE6in4UP(b)     (RX_IPV6ONLY(b) && TX_EIP6in4(b))
#define TE6in4DN(b)     (RX_EIP6in4(b) && TX_IPV6ONLY(b))

#define CHKE4in4(b)     (TE4in4UP(b) || TE4in4DN(b))
#define CHKE6in4(b)     (TE6in4UP(b) || TE6in4DN(b))
#define CHKE46in4(b)    (CHKE4in4(b) || CHKE6in4(b))

#define RX_PPTP(b)       ((b)->rx.info.bmap.PPTP)
#define TX_PPTP(b)       ((b)->tx.info.bmap.PPTP)

#define RX_L2TP(b)       ((b)->rx.info.bmap.L2TP)
#define TX_L2TP(b)       ((b)->tx.info.bmap.L2TP)

#define PKT_IPV6_GET_TOS_WORD(word)       \
   ((ntohl(word) & 0x0FF00000) >> 20)

#define PKT_IPV6_SET_TOS_WORD(word, tos)  \
   (word = htonl((ntohl(word) & 0xF00FFFFF) | ((tos << 20) & 0x0FF00000)))

   
   
typedef struct ip6_addr {
    union {
        uint8_t     p8[16];
        uint16_t    p16[8];
        uint32_t    p32[4];
    };
} ip6_addr_t;


/*
 *------------------------------------------------------------------------------
 * Buffer to log IPv6 Tuple.
 * Packed: 3 16byte cachelines
 *------------------------------------------------------------------------------
 */
struct blogTupleV6_t {
    union {
        uint32_t    word0;
    };

    union {
        uint32_t    word1;
        struct {
            uint16_t length; 
            uint8_t next_hdr; 
            uint8_t rx_hop_limit;
        };
    };

    ip6_addr_t      saddr;
    ip6_addr_t      daddr;

    union {
        ports_t     port;
        uint32_t    ports;
    };

    union {
        struct {
            uint8_t     exthdrs:6;  /* Bit field of IPv6 extension headers */
            uint8_t     fragflag:1; /* 6in4 Upstream IPv4 fragmentation flag */
            uint8_t     tunnel:1;   /* Indication of IPv6 tunnel */
            uint8_t     tx_hop_limit;
            uint16_t    ipid;       /* 6in4 Upstream IPv4 identification */
        };
        uint32_t   word2;
    };

};
typedef struct blogTupleV6_t BlogTupleV6_t;


#define BLOG_ENCAP_MAX          6       /* Maximum number of L2 encaps        */
#define BLOG_HDRSZ_MAX          32      /* Maximum size of L2 encaps          */

typedef enum {
        BLOG_DECL(GRE_ETH)              /* e.g. BLOG_XTMPHY, BLOG_GPONPHY     */
        BLOG_DECL(BCM_XPHY)             /* e.g. BLOG_XTMPHY, BLOG_GPONPHY     */
        BLOG_DECL(BCM_SWC)              /* BRCM LAN Switch Tag/Header         */
        BLOG_DECL(ETH_802x)             /* Ethernet                           */
        BLOG_DECL(VLAN_8021Q)           /* Vlan 8021Q (incld stacked)         */
        BLOG_DECL(PPPoE_2516)           /* PPPoE RFC 2516                     */
        BLOG_DECL(PPP_1661)             /* PPP RFC 1661                       */
        BLOG_DECL(PLD_IPv4)             /* Delivery IPv4                      */
        BLOG_DECL(PLD_IPv6)             /* Delivery IPv6                      */
        BLOG_DECL(PPTP)                 /* PPTP Header                        */
        BLOG_DECL(L2TP)                 /* L2TP Header                        */
        BLOG_DECL(GRE)                  /* GRE Header                         */
        BLOG_DECL(ESP)                  /* ESP Header                         */
        BLOG_DECL(DEL_IPv4)             /* Outer IPv4                         */
        BLOG_DECL(DEL_IPv6)             /* Outer IPv6                         */
        BLOG_DECL(PROTO_MAX)
} BlogEncap_t;


typedef enum {
        BLOG_DECL(BLOG_UPDATE_DPI_QUEUE)  /* DPI Queue assignment has changed */
        BLOG_DECL(BLOG_UPDATE_MAX)
} BlogUpdate_t;

/*
 *------------------------------------------------------------------------------
 * Buffer to log Layer 2 and IP Tuple headers.
 * Packed: 4 16byte cachelines
 *------------------------------------------------------------------------------
 */
struct blogHeader_t {
    BlogTuple_t         tuple;                     /* L3+L4 IP Tuple log */
    void              * dev_p;                     /* physical network device */
    BlogInfo_t          info;
    uint8_t             multicast;                 /* multicast flag */
    uint8_t             count;                     /* # of L2 encapsulations */
    uint8_t             length;                    /* L2 header total length */
    BlogEncap_t         encap[ BLOG_ENCAP_MAX ];   /* All L2 header types */
    uint8_t             l2hdr[ BLOG_HDRSZ_MAX ];   /* Data of all L2 headers */
};

typedef struct blogHeader_t BlogHeader_t;           /* L2 and L3+4 tuple */


union blogWfd_t {
    uint32_t    u32;
    struct {
           uint32_t            chain_idx            : 8;/* Tx chain index */
           uint32_t            priority             : 4;/* Tx Priority */
           uint32_t            reserved0            : 1;/* unused */
           uint32_t            wfd_idx              : 2;/* WFD idx */
           uint32_t            wfd_prio             : 1;/* 0=high, 1=low */
           uint32_t            reserved1            : 12;/* unused */
           uint32_t            is_chain             : 1;/* is_chain=1 */
           uint32_t            is_wfd               : 1;/* is_wfd=1 */
           uint32_t            is_tx_hw_acc_en      : 1;/* =1 if WLAN Transmit is capable of HW Acceleartion */
           uint32_t            is_rx_hw_acc_en      : 1;/* =1 if WLAN Receive is capable of HW Acceleration */
    } nic_ucast;

    struct {
           uint32_t            flowring_idx         :10;/* Tx flowring index */
           uint32_t            priority             : 3;/* Tx Priority */
           uint32_t            wfd_idx              : 2;/* WFD idx */
           uint32_t            reserved1            : 8;/* unused */
           uint32_t            ssid                 : 4;/* SSID for WLAN */
           uint32_t            wfd_prio             : 1;/* 0=high, 1=low */
           uint32_t            is_chain             : 1;/* is_chain=0 */
           uint32_t            is_wfd               : 1;/* is_wfd=1 */
           uint32_t            is_tx_hw_acc_en      : 1;/* =1 if WLAN Transmit is capable of HW Acceleartion */
           uint32_t            is_rx_hw_acc_en      : 1;/* =1 if WLAN Receive is capable of HW Acceleration */
    } dhd_ucast;

    struct {
           uint32_t            reserved0            :19;/* unused */
           uint32_t            ssid                 : 4;/* SSID */
           uint32_t            reserved1            : 2;/* unused */
           uint32_t            wfd_prio             : 1;/* 0=high, 1=low */
           uint32_t            wfd_idx              : 2;/* WFD idx */
           uint32_t            is_chain             : 1;/* is_chain=0 */
           uint32_t            is_wfd               : 1;/* is_wfd=1 */
           uint32_t            is_tx_hw_acc_en      : 1;/* =1 if WLAN Transmit is capable of HW Acceleartion */
           uint32_t            is_rx_hw_acc_en      : 1;/* =1 if WLAN Receive is capable of HW Acceleration */
    } mcast;
};
typedef union blogWfd_t BlogWfd_t;

struct blogRnr_t {
       uint32_t            flowring_idx         :10;/* Tx flowring index */
       uint32_t            reserved1            : 9;/* unused */
       uint32_t            ssid                 : 4;/* SSID */
       uint32_t            priority             : 3;/* Tx Priority */
       uint32_t            reserved0            : 1;/* unused */
       uint32_t            radio_idx            : 2;/* Radio index */
       uint32_t            is_wfd               : 1;/* rnr (is_wfd=0) */
       uint32_t            is_tx_hw_acc_en      : 1;/* =1 if WLAN Transmit is capable of HW Acceleartion */
       uint32_t            is_rx_hw_acc_en      : 1;/* =1 if WLAN Receive is capable of HW Acceleration */
};

typedef struct blogRnr_t BlogRnr_t;


/* Coarse hash key: L1, L3, L4 hash */
union blogHash_t {
    uint8_t     protocol;           /* IP protocol */
};

typedef union blogHash_t BlogHash_t;




/*
 *------------------------------------------------------------------------------
 * TCP ACK flow prioritization.
 * Any of the parameters given below can be changed based on the requirements. 
 * The len parameter is IPv4/6 total/payload length and does not include any 
 * L2 fields (like MAC DA, SA, EthType, VLAN, etc.)
 *------------------------------------------------------------------------------
 */
#define BLOG_TCPACK_IPV4_LEN   64   /* IPv4 total len value for pure TCP ACK  */
#define BLOG_TCPACK_IPV6_LEN   32   /* IPv6 len value for pure TCP ACK        */
#define BLOG_TCPACK_MAX_COUNT   4   /* max # of back-to-back TCP ACKs received
                                       after which the ACK flow is prioritized */
#define BLOG_TCPACK_XTM_PRIO    1   /* TCP ACK packets will be sent to priority 1
                                       queue. If the queue does not exist,
                                       packets will be sent to the default queue,
                                       which is the first queue configured for
                                       the interface. */

#define MAX_NUM_VLAN_TAG        2



struct blog_t {
    BlogHash_t          key;            /* Coarse hash search key */
    union {
        BlogWfd_t       wfd;
        BlogRnr_t       rnr;
    };
    
    uint8_t             vtag_num;
    uint16_t            eth_type;

    union {
        uint32_t        flags;
        struct {
            uint32_t    rsvd:        11;    
            uint32_t    is_mapt_us:  1; /* MAP-T Upstream flow */   
            uint32_t    is_df:       1; /* IPv4 DF flag set */
            uint32_t    lag_port:    2; /* LAG port when trunking is done by internal switch/runner */
            uint32_t    ptm_us_bond: 1; /* PTM US Bonding Mode */
            uint32_t    tos_mode_us: 1; /* ToS mode for US: fixed, inherit */
            uint32_t    tos_mode_ds: 1; /* ToS mode for DS: fixed, inherit */
            uint32_t    has_pppoe:   1;
            uint32_t    ack_cnt:     4; /* back to back TCP ACKs for prio */
            uint32_t    ack_done:    1; /* TCP ACK prio decision made */
            uint32_t    nf_dir_pld:  1;
            uint32_t    nf_dir_del:  1;
            uint32_t    pop_pppoa:   1;
            uint32_t    insert_eth:  1;
            uint32_t    iq_prio:     1;  /* not used */
            uint32_t    mc_sync:     1;
            uint32_t    rtp_seq_chk: 1; /* RTP sequence check enable       */
            uint32_t    incomplete:  1;
        };
    };

    unsigned long       mark;           /* NF mark value on tx */
    uint32_t            priority;       /* Tx  priority */
    blogRule_t          * blogRule_p;   /* List of Blog Rules */

    /* vtag[] stored in network order to improve fcache performance */
    uint32_t            vtag[MAX_NUM_VLAN_TAG];

    BlogTupleV6_t       tupleV6;        /* L3+L4 IP Tuple log */

    BlogHeader_t        tx;             /* Transmit path headers */
    BlogHeader_t        rx;             /* Receive path headers */

    void                *tx_dev_p;      /* TX physical network device */

    uint8_t             mcast_learn;
    uint8_t             is_ssm;
    uint8_t             dpi_queue;
};

typedef struct blog_t Blog_t;
// typedef struct blog_t Blog;

#endif /* defined(__BLOG_H_INCLUDED__) */

