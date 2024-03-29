/* $Id: lim.common.h 397 2007-11-26 19:04:00Z mblack $
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

#include "lim.h"
#include <math.h>

#define  SWP_INTVL_CNT   45/exchIntvl       
#define  TMP_INTVL_CNT   120/exchIntvl      
#define  PAGE_INTVL_CNT   120/exchIntvl      

#include <utmp.h>

extern int pipefd[2];
extern struct limLock limLock;


static void smooth(float *, float, float);
void sendLoad(void);
static float idletime(int *);
static float tmpspace(void);
static float getswap(void);
static float getpaging(float);
static float getIoRate(float);
static void getusr(void);

static int numCpus(void);

int  maxnLbHost;        
int  ncpus=1;           

float cpu_usage = 0.0;
#ifdef MEAS
float realcla = 0.0;        
int sd_cnt = 0;
int rcv_cnt = 0;            
#endif

