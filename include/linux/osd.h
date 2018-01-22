/*
 * Copyright (c) 2015 Los Alamos Nat. Security, LLC. All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _LINUX_OSD_H_
#define _LINUX_OSD_H_

/*#define _GNU_SOURCE*/

#include <byteswap.h>
#include <endian.h>
#include <sys/mman.h>
#include <string.h>
#include <assert.h>

#include "unix/osd.h"
#include "rdma/fi_errno.h"

static inline int ofi_shm_remap(struct util_shm *shm,
				size_t newsize, void **mapped)
{
	shm->ptr = mremap(shm->ptr, shm->size, newsize, 0);
	shm->size = newsize;
	*mapped = shm->ptr;
	return shm->ptr == MAP_FAILED ? -FI_EINVAL : FI_SUCCESS;
}


#ifdef HAVE_LINUX_PERF_EVENT_H
#define HAVE_OFI_PERF
#endif /* HAVE_LINUX_PERF_EVENT_H */


#endif /* _LINUX_OSD_H_ */

