/* $Id: limout.h 397 2007-11-26 19:04:00Z mblack $
 * Copyright (C) 2007 Platform Computing Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
 */

#ifndef LIMOUT_H
#define LIMOUT_H

#include "../lib/lib.hdr.h"


enum ofWhat {OF_ANY, OF_HOSTS, OF_TYPE};

typedef enum ofWhat ofWhat_t;

struct decisionReq {
    ofWhat_t  ofWhat;
    int       options;
    char      hostType[MAXLSFNAMELEN];
    int       numHosts;
    char      resReq[MAXLINELEN];
    int       numPrefs;
    char      **preferredHosts;
};

struct placeReply {
    int   numHosts;
    struct placeInfo *placeInfo;
};

struct jobXfer {
    int  numHosts;
    char resReq[MAXLINELEN];
    struct placeInfo *placeInfo;
};

enum limReqCode {
    
    LIM_PLACEMENT     = 1 + VENDOR_CODE,
    LIM_LOAD_REQ      = 2 + VENDOR_CODE,
    LIM_LOAD_ADJ      = 3 + VENDOR_CODE,
    LIM_GET_CLUSNAME  = 4 + VENDOR_CODE,
    LIM_GET_MASTINFO  = 5 + VENDOR_CODE,
    LIM_GET_HOSTINFO  = 6 + VENDOR_CODE,
    LIM_GET_CPUF      = 7 + VENDOR_CODE,
    LIM_GET_INFO      = 8 + VENDOR_CODE,
    LIM_GET_CLUSINFO  = 9 + VENDOR_CODE,
    LIM_PING          = 10 + VENDOR_CODE,
    LIM_CHK_RESREQ    = 11 + VENDOR_CODE,
    LIM_DEBUGREQ      = 12 + VENDOR_CODE,
    LIM_GET_RESOUINFO = 13 + VENDOR_CODE,
    LIM_SLIMCONF_REQ  = 15 + VENDOR_CODE, 

    
#define FIRST_LIM_PRIV	LIM_REBOOT
    LIM_REBOOT        = 50 + VENDOR_CODE,
    LIM_LOCK_HOST     = 51 + VENDOR_CODE,
    LIM_SERV_AVAIL    = 52 + VENDOR_CODE,
    LIM_SHUTDOWN      = 53 + VENDOR_CODE,

    
#define FIRST_LIM_LIM	LIM_LOAD_UPD
    LIM_LOAD_UPD      = 100 + VENDOR_CODE,
    LIM_JOB_XFER      = 101 + VENDOR_CODE,
    LIM_MASTER_ANN    = 102 + VENDOR_CODE,
    LIM_CONF_INFO     = 103 + VENDOR_CODE,  

    
#define FIRST_INTER_CLUS  LIM_CLUST_INFO
    LIM_CLUST_INFO   = 200 + VENDOR_CODE,
    LIM_HINFO_REQ    = 201 + VENDOR_CODE,
    LIM_HINFO_REPLY  = 202 + VENDOR_CODE,
    LIM_LINFO_REQ    = 203 + VENDOR_CODE,
    LIM_LINFO_REPLY  = 204 + VENDOR_CODE
};

enum limReplyCode {
    LIME_NO_ERR           = 1,         
    LIME_WRONG_MASTER     = 2,         
    LIME_BAD_RESREQ       = 3,         
    LIME_NO_OKHOST        = 4,         
    LIME_NO_ELHOST        = 5,         
    LIME_BAD_DATA         = 6,         
    LIME_BAD_REQ_CODE     = 7,         
    LIME_MASTER_UNKNW     = 8,         
    LIME_DENIED           = 9,         
    LIME_IGNORED          = 10,        
    LIME_UNKWN_HOST       = 11,        
    LIME_UNKWN_MODEL      = 12,        
    LIME_LOCKED_AL        = 13,        
    LIME_NOT_LOCKED       = 14,        
    LIME_BAD_SERVID       = 15,        
    LIME_NAUTH_HOST       = 16,        
    LIME_UNKWN_RNAME      = 17,        
    LIME_UNKWN_RVAL       = 18,        
    LIME_NO_ELCLUST       = 20,        
    LIME_NO_MEM           = 21,        
    LIME_BAD_FILTER       = 22,        
    LIME_BAD_RESOURCE     = 23,	       
    LIME_NO_RESOURCE      = 24,        
    LIME_CONF_NOTREADY    = 25,        
};

struct loadReply {
    int    nEntry;
    int    nIndex;
    char   **indicies; 	
    struct hostLoad *loadMatrix;
#define LOAD_REPLY_SHARED_RESOURCE 0x1
    int  flags;
};

struct shortHInfo {
    char    hostName[MAXHOSTNAMELEN];
    int     hTypeIndx;
    int     hModelIndx;
    int     maxCpus;
    int     maxMem;
    int     maxSwap;
    int     maxTmp;
    int     nDisks;
    int     resClass;
    char    *windows;
    float   *busyThreshold;
    int	    flags;
#define HINFO_SERVER		0x01
#define HINFO_SHARED_RESOURCE   0x02
    int     rexPriority; 
    int     nRInt;
    int     *resBitMaps;
};

struct shortLsInfo {
    int    nRes;		
    char   **resName;
    int    nTypes;
    char   *hostTypes[MAXTYPES];
    int    nModels;
    char   *hostModels[MAXMODELS];
    float  cpuFactors[MAXMODELS];
    int    *stringResBitMaps;
    int    *numericResBitMaps;
};

struct hostInfoReply {
    int    nHost;
    int    nIndex;
    struct shortLsInfo *shortLsInfo;
    struct shortHInfo  *hostMatrix;
};

struct clusterInfoReq {
    char *resReq;
    int  listsize;                      
    char **clusters;                    
    int  options;
};


struct shortCInfo {
    char  clName[MAXLSFNAMELEN];         
    char  masterName[MAXHOSTNAMELEN];    
    char  managerName[MAXLSFNAMELEN];    
    int   managerId;                     
    int   status;                        
    int   resClass;                      
    int   typeClass;                     
    int   modelClass;                    
    int   numIndx;                       
    int   numUsrIndx;                    
    int   usrIndxClass;                  
    int   numServers;                    
    int   numClients;                    
    int   nAdmins;                       
    int   *adminIds;                     
    char  **admins;                      
    int   nRes;                          
    int   *resBitMaps;                   
    int   nTypes;
    int   *hostTypeBitMaps;              
    int   nModels;
    int   *hostModelBitMaps;             
};

struct cInfo {
    char  clName[MAXLSFNAMELEN];         
    char  masterName[MAXHOSTNAMELEN];    
    char  managerName[MAXLSFNAMELEN];    
    int   managerId;                     
    int   status;                        
    int   resClass;                      
    int   typeClass;                     
    int   modelClass;                    
    int   numIndx;                       
    int   numUsrIndx;                    
    int   usrIndxClass;                  
    int   numServers;                    
    int   numClients;                    
    int   nAdmins;                       
    int   *adminIds;                     
    char  **admins;                      
    int   nRes;                          
    int   *resBitMaps;                   
    char  **loadIndxNames;               
    struct shortLsInfo shortInfo;        
    int   nTypes;
    int   *hostTypeBitMaps;              
    int   nModels;
    int   *hostModelBitMaps;             
};

struct clusterInfoReply {
    int     nClus;
    struct  shortLsInfo *shortLsInfo;
    struct  shortCInfo *clusterMatrix;
};

struct masterInfo {
    char    hostName[MAXHOSTNAMELEN];
    u_int   addr;     
    u_short portno;   
};


struct clusterList {
    int  nClusters;
    char **clNames;
};

#define   LIM_UNLOCK_USER      0     
#define   LIM_LOCK_USER        1     
#define   LIM_UNLOCK_MASTER    2    
#define   LIM_LOCK_MASTER      3    

#define   LIM_LOCK_STAT_USER      0x1   
#define   LIM_LOCK_STAT_MASTER    0x2   

#define   LOCK_BY_USER(stat)     (((stat) & LIM_LOCK_STAT_USER) != 0) 
#define   LOCK_BY_MASTER(stat)   (((stat) & LIM_LOCK_STAT_MASTER) != 0)

#define   WINDOW_RETRY         0   
#define   WINDOW_OPEN          1   
#define   WINDOW_CLOSE         2   
#define   WINDOW_FAIL          3   

        
struct limLock {
    int uid;
    int on;
    time_t time;
    char lsfUserName[MAXLSFNAMELEN];
};


#include "../lib/lib.xdrlim.h"

#endif
