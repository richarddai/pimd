/*
 * Copyright (c) 1998-2001
 * University of Southern California/Information Sciences Institute.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef __PIMD_IGMPV3_H__
#define __PIMD_IGMPV3_H__

/* V3 group record types [grec_type] */
#define IGMP_REPORT_MODE_IN	1
#define IGMP_REPORT_MODE_EX	2
#define IGMP_REPORT_TO_IN	3
#define IGMP_REPORT_TO_EX	4
#define IGMP_REPORT_ALLOW_NEW	5
#define IGMP_REPORT_BLOCK_OLD	6

struct igmp_grouprec {
    u_char	    ig_type;	    /* record type */
    u_char	    ig_datalen;	    /* length of auxiliary data */
    u_short	    ig_numsrc;	    /* number of sources */
    struct in_addr  ig_group;	    /* group address being reported */
    struct in_addr  ig_sources[0];  /* source addresses */
};
 
struct igmp_report {
    u_char	    ir_type;	    /* record type */
    u_char	    ir_rsv1;	    /* reserved */
    u_short	    ir_cksum;	    /* checksum */
    u_short	    ir_rsv2;	    /* reserved */
    u_short	    ir_numgrps;	    /* number of group records */
    struct	    igmp_grouprec ir_groups[0];	    /* group records */
};

#endif /* __PIMD_IGMPV3_H__ */

/**
 * Local Variables:
 *  version-control: t
 *  indent-tabs-mode: t
 *  c-file-style: "ellemtel"
 *  c-basic-offset: 4
 * End:
 */
