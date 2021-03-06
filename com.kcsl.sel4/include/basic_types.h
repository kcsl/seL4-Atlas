/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __BASIC_TYPES_H
#define __BASIC_TYPES_H

#include <stdint.h>
#include <arch/x86/arch/types.h>

enum _bool {
    false = 0,
    true  = 1
};
typedef word_t bool_t;

typedef struct region {
    pptr_t start;
    pptr_t end;
} region_t;

typedef struct p_region {
    paddr_t start;
    paddr_t end;
} p_region_t;

typedef struct v_region {
    vptr_t start;
    vptr_t end;
} v_region_t;

#define REG_EMPTY (region_t){ .start = 0, .end = 0 }
#define P_REG_EMPTY (p_region_t){ .start = 0, .end = 0 }

/* equivalent to a word_t except that we tell the compiler that we may alias with
 * any other type (similar to a char pointer) */
typedef word_t __attribute__((__may_alias__)) word_t_may_alias;

#endif /* __BASIC_TYPES_H */
