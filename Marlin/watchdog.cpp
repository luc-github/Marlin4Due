#include "Marlin.h"

#ifdef USE_WATCHDOG

#include "watchdog.h"
#include "ultralcd.h"

//===========================================================================
//============================ private variables ============================
//===========================================================================

//===========================================================================
//================================ functions ================================
//===========================================================================

// INTERVAL / (32Khz/128)  = seconds
#define WATCHDOG_INTERVAL       1024u  // 8sec  (~16 seconds max)

/// intialise watch dog with a 8 sec interrupt time
void watchdog_init()
{
#ifdef USE_WATCHDOG
WDT->WDT_MR = WDT_MR_WDRSTEN | WATCHDOG_INTERVAL | (WATCHDOG_INTERVAL << 16);WDT->WDT_CR = 0xA5000001;
#endif
}

/// reset watchdog. MUST be called every 1s after init or due will reset.
void watchdog_reset() 
{
#ifdef USE_WATCHDOG
    WDT->WDT_CR = 0xA5000001;
#endif
}

#endif//USE_WATCHDOG
