//
//  shm_ipc_common.c
//  shm_ipc_client
//
//  Created by Jaim Zuber on 8/31/20.
//  Copyright © 2020 Remotion. All rights reserved.
//

#include "shm_ipc_common.h"

void forkAndMap(mach_port_t mach_port) {
    fork();

    mapMachPort(mach_port);
}

void mapMachPort(mach_port_t mach_port) {

    mach_vm_address_t address = NULL;

    kern_return_t returnValue = mach_vm_map(
                mach_task_self(),
                &address,
                vm_page_size,
                0,
                VM_FLAGS_ANYWHERE,
                mach_port,
                0,
                FALSE,
                VM_PROT_READ|VM_PROT_WRITE,
                VM_PROT_READ|VM_PROT_WRITE,
                VM_INHERIT_NONE);

    if (returnValue != KERN_SUCCESS)
        mach_error("vm_map", returnValue);
    else {
        printf("success!\n");
    }
}


