/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support  -  ROUSSET  -
 * ----------------------------------------------------------------------------
 * Copyright (c) 2006, Atmel Corporation

 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
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
 * File Name           : cstartup.S
 * Object              : 
 * Creation            : FDy Nov 10th 2006
 * Updates             : ODi Nov 20th 2006 Cleanup
 *-----------------------------------------------------------------------------
 */

#include "project.h"

#define TOP_OF_MEMORY    (AT91C_IRAM + AT91C_IRAM_SIZE)
#define ABT_STACK_SIZE   8*3*4
#define IRQ_STACK_SIZE   8*3*4

#define ARM_MODE_ABT     0x17
#define ARM_MODE_FIQ     0x11
#define ARM_MODE_IRQ     0x12
#define ARM_MODE_SVC     0x13

#define I_BIT            0x80
#define F_BIT            0x40


/* Application startup entry point */
        .globl reset_handler
        .align 4

.section .vectors
.arm
	        

/* Exception vectors (should be a branch to be detected as a valid code by the rom */
_exception_vectors:
reset_vector:
        ldr      pc, =reset_handler
undef_vector:
        b        undef_vector    /* Undefined Instruction */
swi_vector:
        b        swi_vector      /* Software Interrupt */
pabt_vector:
    //    ldr      pc, =pabt_handler     /* Prefetch Abort */
dabt_vector:
//        ldr      pc, =dabt_handler     /* Data Abort */
rsvd_vector:
        b        rsvd_vector     /* reserved */
irq_vector:
        b        irq_handler     /* IRQ : read the AIC */
fiq_vector:
/*------------------------------------------------------------------------------
 *- Function             : fiq_handler
 *- Treatments           : FIQ Interrupt Handler.
 *- Called Functions     : 
 *------------------------------------------------------------------------------*/
fiq_handler:
	b        fiq_handler
	
/*------------------------------------------------------------------------------
 *- Function             : irq_handler
 *- Treatments           : IRQ Controller Interrupt Handler.
 *- Called Functions     : AIC_IVR[interrupt]
 *------------------------------------------------------------------------------*/
irq_handler:
/*- Manage Exception Entry */
/*- Adjust and save LR_irq in IRQ stack */
        sub      lr, lr, #4
        stmfd    sp!, {lr}
/*- Save r0 and SPSR in IRQ stack */
        mrs      r14, SPSR
        stmfd    sp!, {r0,r14}

/*- Write in the IVR to support Protect Mode */
/*- No effect in Normal Mode */
/*- De-assert the NIRQ and clear the source in Protect Mode */
        ldr      r14, =AT91C_BASE_AIC
        ldr      r0 , [r14, #AIC_IVR]
        str      r14, [r14, #AIC_IVR]

/*- Enable Interrupt and Switch in Supervisor Mode */
        msr      CPSR_c, #ARM_MODE_SVC

/*- Save scratch/used registers and LR in User Stack */
        stmfd    sp!, {r1-r3, r12, r14}

/*- Branch to the routine pointed by the AIC_IVR */
        mov      r14, pc
        bx       r0

/*- Restore scratch/used registers and LR from User Stack */
        ldmia    sp!, {r1-r3, r12, r14}

/*- Disable Interrupt and switch back in IRQ mode */
        msr      CPSR_c, #ARM_MODE_IRQ | I_BIT

/*- Mark the End of Interrupt on the AIC */
        ldr      r14, =AT91C_BASE_AIC
        str      r14, [r14, #AIC_EOICR]

/*- Restore SPSR_irq and r0 from IRQ stack */
        ldmia    sp!, {r0,r14}
        msr      SPSR_cxsf, r14

/*- Restore adjusted  LR_irq from IRQ stack directly in the PC */
        ldmia    sp!, {pc}^

/*------------------------------------------------------------------------------
 *- Function             : reset_handler
 *- Treatments           : Reset Interrupt Handler.
 *- Called Functions     : lowlevel_init
 *                         main
 *------------------------------------------------------------------------------*/
.section .text
reset_handler:
	ldr     pc, =_low_level_init

/*------------------------------------------------------------------------------
 *- Low level Init is performed in a C function: lowlevel_init
 *- Init Stack Pointer to a valid memory area before calling lowlevel_init
 *------------------------------------------------------------------------------*/
/*- Temporary stack in internal RAM for Low Level Init execution */
_low_level_init:
	ldr      r2, =_lp_ll_init
        ldmia    r2, {r0, r1}
        mov      sp, r1
        mov      lr, pc
        bx       r0                      /* Branch on C function (interworking) */

/*------------------------------------------------------------------------------
 *- Setup the stack for each mode
 *------------------------------------------------------------------------------*/
_stack_init:
	ldr      r2, =_lp_stack_init
        ldmia    r2, {r0, r1, r2}

/*- Set up Abort Mode and set ABT Mode Stack */
        msr      CPSR_c, #ARM_MODE_ABT | I_BIT | F_BIT
        mov      sp, r0
        sub      r0, r0, r1

/*- Set up Interrupt Mode and set IRQ Mode Stack */
        msr      CPSR_c, #ARM_MODE_IRQ | I_BIT | F_BIT
        mov      sp, r0
        sub      r0, r0, r2

/*- Enable interrupt & Set up Supervisor Mode and set Supervisor Mode Stack */
        msr      CPSR_c, #ARM_MODE_SVC | F_BIT
        mov      sp, r0

/*------------------------------------------------------------------------------
 *- Segments initialization
 *------------------------------------------------------------------------------*/
/* Copy the data section in RAM at 0x0000 */
_init_data:
	ldr      r2, =_lp_data
        ldmia    r2, {r1, r3, r4}
1:
        cmp      r3, r4
        ldrcc    r2, [r1], #4
        strcc    r2, [r3], #4
        bcc      1b

/* Clear the bss segment */
_init_bss:
	ldr      r2, =_lp_bss
        ldmia    r2, {r3, r4}
        mov      r2, #0
1:
        cmp      r3, r4
        strcc    r2, [r3], #4
        bcc      1b

/*------------------------------------------------------------------------------
 *- Branch to the main
 *------------------------------------------------------------------------------*/
_branch_main:
        ldr      r0, =main
        mov      lr, pc
        bx       r0

/*------------------------------------------------------------------------------
 *- Litteral pools
 *------------------------------------------------------------------------------*/
_lp_ll_init:
        .word    lowlevel_init
        .word    TOP_OF_MEMORY              /* Default SVC stack after power up */ 

_lp_stack_init:
        .word    TOP_OF_MEMORY             /* Top of the stack */
        .word    ABT_STACK_SIZE            /* ABT stack size */
        .word    IRQ_STACK_SIZE            /* IRQ stack size */

_lp_bss:
        .word    _sbss
        .word    _ebss

_lp_data:
        .word    _etext
        .word    _sdata
        .word    _edata

