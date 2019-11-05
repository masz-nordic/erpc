/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "erpc_manually_constructed.h"
#include "erpc_rpmsg_lite_transport.h"
#include "erpc_transport_setup.h"

using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

#if !defined(SH_MEM_TOTAL_SIZE)
#define SH_MEM_TOTAL_SIZE (6144)
#endif

static ManuallyConstructed<RPMsgTransport> s_transport;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

erpc_transport_t erpc_transport_rpmsg_lite_master_init(unsigned long src_addr, unsigned long dst_addr,
                                                       int rpmsg_link_id)
{
    s_transport.construct();
    if (s_transport->init(src_addr, dst_addr, (void *)(0x20010000 + 0x400), 0x7C00, rpmsg_link_id) == kErpcStatus_Success)
    {
        return reinterpret_cast<erpc_transport_t>(s_transport.get());
    }
    return NULL;
}
