/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support  -  ROUSSET  -
 * ----------------------------------------------------------------------------
 * Copyright (c) 2006, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaiimer below.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the disclaimer below in the documentation and/or
 * other materials provided with the distribution.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */
/*-----------------------------------------------------------------------------
 *  File Name           : lowlevel.c
 *  Object              : low level initialization file
 *  Creation            : FDy   20-Nov-2006
 *-----------------------------------------------------------------------------
 */

/* Include Standard files */
#include "project.h"


/*-----------------------------------------------------------------------------
 * Function Name       : default_spurious_handler
 * Object              : default handler for spurious interrupt
 *-----------------------------------------------------------------------------*/
void default_spurious_handler(void)
{
    dbgu_print_ascii("-F- Spurious Interrupt\n\r ");
    while (1);
}

/*-----------------------------------------------------------------------------
 * Function Name       : default_fiq_handler
 * Object              : default handler for fast interrupt
 *-----------------------------------------------------------------------------*/
void default_fiq_handler(void)
{
    dbgu_print_ascii("-F- Unexpected FIQ Interrupt\n\r ");
    while (1);
}

/*-----------------------------------------------------------------------------
 * Function Name       : default_irq_handler
 * Object              : default handler for irq
 *-----------------------------------------------------------------------------*/
void default_irq_handler(void)
{
    dbgu_print_ascii("-F- Unexpected IRQ Interrupt\n\r ");
    while (1);
}

/*-----------------------------------------------------------------------------
 * Function Name       : lowlevel_init
 * Object              : This function performs very low level HW initialization
 *                       this function can use a Stack, depending the compilation
 *                       optimization mode
 *-----------------------------------------------------------------------------*/
void lowlevel_init(void)
{
    unsigned char i = 0;

    ///////////////////////////////////////////////////////////////////////////
    // Init PMC Step 1. Enable Main Oscillator
    // Main Oscillator startup time is board specific:
    // Main Oscillator Startup Time worst case (3MHz) corresponds to 15ms
    // (0x40 for AT91C_CKGR_OSCOUNT field)
    ///////////////////////////////////////////////////////////////////////////
    AT91C_BASE_PMC->PMC_MOR = (((AT91C_CKGR_OSCOUNT & (0x40 << 8)) | AT91C_CKGR_MOSCEN));
    // Wait Main Oscillator stabilization
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCS));

    ///////////////////////////////////////////////////////////////////////////
    // Init PMC Step 2.
    // Set PLLA to 200MHz (198,656MHz)
    // PLL Startup time depends on PLL RC filter: worst case is choosen
    ///////////////////////////////////////////////////////////////////////////
    AT91C_BASE_PMC->PMC_PLLAR = AT91C_CKGR_SRCA                  |
                                AT91C_CKGR_OUTA_2                |
                                (0x3F << 8)                      |
                                (AT91C_CKGR_MULA & (0x6D << 16)) |
                                (AT91C_CKGR_DIVA & 9);
    // Wait for PLLA stabilization
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCKA));
    // Wait until the master clock is established for the case we already
    // turn on the PLLA
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    ///////////////////////////////////////////////////////////////////////////
    // Init PMC Step 3.
    // Selection of Master Clock MCK equal to (Processor Clock PCK) PLLA/2=100MHz
    // The PMC_MCKR register must not be programmed in a single write operation
    // (see. Product Errata Sheet)
    ///////////////////////////////////////////////////////////////////////////
    AT91C_BASE_PMC->PMC_MCKR = AT91C_PMC_PRES_CLK | AT91C_PMC_MDIV_2;
    // Wait until the master clock is established
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    AT91C_BASE_PMC->PMC_MCKR |= AT91C_PMC_CSS_PLLA_CLK;
    // Wait until the master clock is established
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    ///////////////////////////////////////////////////////////////////////////
    // Reset AIC: assign default handler for each interrupt source
    ///////////////////////////////////////////////////////////////////////////
    AT91C_BASE_AIC->AIC_SVR[0] = (int) default_fiq_handler ;
    for (i = 1; i < 31; i++) {
        AT91C_BASE_AIC->AIC_SVR[i] = (int) default_irq_handler ;
    }
    AT91C_BASE_AIC->AIC_SPU = (unsigned int) default_spurious_handler;

    // Perform 8 IT acknoledge (write any value in EOICR)
    for (i = 0; i < 8 ; i++) {
        AT91C_BASE_AIC->AIC_EOICR = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Disable Watchdog
    ///////////////////////////////////////////////////////////////////////////
    AT91C_BASE_WDTC->WDTC_WDMR = AT91C_WDTC_WDDIS;

    ///////////////////////////////////////////////////////////////////////////
    // Remap
    ///////////////////////////////////////////////////////////////////////////
    AT91C_BASE_MATRIX->MATRIX_MRCR = AT91C_MATRIX_RCA926I | AT91C_MATRIX_RCA926D;
}
