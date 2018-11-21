/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __PLAT_MACHINE_HARDWARE_H
#define __PLAT_MACHINE_HARDWARE_H

#include <plat/pc99/plat/machine/interrupt.h>
#include <plat/pc99/plat/machine.h>
#include <build/generated/plat_mode/machine/hardware_gen.h>
#include <plat/pc99/plat/64/plat_mode/machine/hardware.h>

bool_t platAddDevices(void);

#endif
