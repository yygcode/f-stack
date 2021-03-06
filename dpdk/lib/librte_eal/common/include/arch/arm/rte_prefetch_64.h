/*
 *   BSD LICENSE
 *
 *   Copyright (C) Cavium, Inc. 2015.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Cavium, Inc nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _RTE_PREFETCH_ARM_64_H_
#define _RTE_PREFETCH_ARM_64_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <rte_common.h>
#include "generic/rte_prefetch.h"

static inline void rte_prefetch0(const volatile void *p)
{
	asm volatile ("PRFM PLDL1KEEP, [%0]" : : "r" (p));
}

static inline void rte_prefetch1(const volatile void *p)
{
	asm volatile ("PRFM PLDL2KEEP, [%0]" : : "r" (p));
}

static inline void rte_prefetch2(const volatile void *p)
{
	asm volatile ("PRFM PLDL3KEEP, [%0]" : : "r" (p));
}

static inline void rte_prefetch_non_temporal(const volatile void *p)
{
	asm volatile ("PRFM PLDL1STRM, [%0]" : : "r" (p));
}

#ifdef __cplusplus
}
#endif

#endif /* _RTE_PREFETCH_ARM_64_H_ */
