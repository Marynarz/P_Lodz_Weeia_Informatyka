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
 *  File Name           : AT91SAM9263-EK.h
 *  Object              : AT91SAM9263-EK Evaluation Board Features Definition File
 *  Creation            : FDy   10-Nov-2006
 *-----------------------------------------------------------------------------
 */
#ifndef AT91SAM9263_EK_H
#define AT91SAM9263_EK_H


/*-----------------*/
/* LEDs Definition */
/*-----------------*/
#define AT91B_LED1           AT91C_PIO_PB8   /* DS1 */
#define AT91B_LED2           AT91C_PIO_PC29  /* DS2 */
#define AT91B_NB_LEB         2
#define AT91D_BASE_PIO_LED1  (AT91C_BASE_PIOB)
#define AT91D_BASE_PIO_LED2  (AT91C_BASE_PIOC)
#define AT91D_ID_PIO_LED1    (AT91C_ID_PIOB)
#define AT91D_ID_PIO_LED2    (AT91C_ID_PIOC)

/*-------------------------------*/
/* Push Button Definition  */
/*-------------------------------*/
#define AT91B_BP1            AT91C_PIO_PC5  // Left click
#define AT91B_BP2            AT91C_PIO_PC4  // Right clic
#define AT91D_BASE_PIO_BP    AT91C_BASE_PIOC
#define AT91D_ID_PIO_BP      AT91C_ID_PIOCDE

/*-------------------------------*/
/* Push Button Definition  */
/*-------------------------------*/
#define AT91D_ID_TC          AT91C_ID_TC012



#define AT91B_DBGU_BAUD_RATE	115200

/*---------------*/
/* SPI interface */
/*---------------*/
/* MN5 SERIAL DATAFLASH AT45DB642E
   SPI   Name : Port
   SPI  SCK  PA14 / SPI_SPCK
   CS        PA11 / SPI_NPCS0
   SO        PA12 /SPI_MISO
   SI        PA13 /SPI_MOSI
*/
#define DATAFLASH_PERI Peripheral_A
#define DATAFLASH_SI   AT91C_PA13_MOSI
#define DATAFLASH_SO   AT91C_PA12_MISO
#define DATAFLASH_CS   AT91C_PA11_NPCS0
#define DATAFLASH_SCK  AT91C_PA14_SPCK

/*---------------*/
/* Clocks       */
/*--------------*/
#define AT91B_MAIN_OSC        16367660              // Main Oscillator MAINCK
#define AT91B_MCK             ((16367660*110/9)/2)   // Output PLLA Clock / 2 (~100 MHz)
#define AT91B_MASTER_CLOCK    AT91B_MCK
#define AT91B_SLOW_CLOCK      32768


#endif /* AT91SAM9263-EK_H */
