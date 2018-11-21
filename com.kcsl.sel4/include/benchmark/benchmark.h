/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <arch/x86/arch/benchmark.h>
#include <machine/io.h>
#include <arch/x86/arch/api/constants.h>
#include <arch/x86/arch/machine/hardware.h>
#include <benchmark/benchmark_tracepoints_types.h>
#include <arch/x86/arch/64/mode/hardware.h>

#if CONFIG_MAX_NUM_TRACE_POINTS > 0
#define TRACE_POINT_START(x) trace_point_start(x)
#define TRACE_POINT_STOP(x)   trace_point_stop(x)

#define MAX_LOG_SIZE (seL4_LogBufferSize / sizeof(benchmark_tracepoint_log_entry_t))

extern timestamp_t ksEntries[CONFIG_MAX_NUM_TRACE_POINTS];
extern bool_t ksStarted[CONFIG_MAX_NUM_TRACE_POINTS];
extern timestamp_t ksExit;
extern seL4_Word ksLogIndex;
extern seL4_Word ksLogIndexFinalized;
extern paddr_t ksUserLogBuffer;

static inline void
trace_point_start(word_t id)
{
    ksEntries[id] = timestamp();
    ksStarted[id] = true;
}

static inline void
trace_point_stop(word_t id)
{
    benchmark_tracepoint_log_entry_t *ksLog = (benchmark_tracepoint_log_entry_t *) KS_LOG_PPTR;
    ksExit = timestamp();

    if (likely(ksUserLogBuffer != 0)) {
        if (likely(ksStarted[id])) {
            ksStarted[id] = false;
            if (likely(ksLogIndex < MAX_LOG_SIZE)) {
                ksLog[ksLogIndex] = (benchmark_tracepoint_log_entry_t) {
                    id, ksExit - ksEntries[id]
                };
            }
            /* increment the log index even if we have exceeded the log size
             * this is so we can tell if we need a bigger log */
            ksLogIndex++;
        }
        /* If this fails integer overflow has occurred. */
        assert(ksLogIndex > 0);
    }
}

#else

#define TRACE_POINT_START(x)
#define TRACE_POINT_STOP(x)

#endif /* CONFIG_MAX_NUM_TRACE_POINTS > 0 */

#endif /* BENCHMARK_H */
