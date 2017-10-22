.global main

.arm

.EQU    PIOB_PER,    0xFFFFF400		// PIOB enable
.EQU    PIOB_PDR,    0xFFFFF404		// PIOB disable
.EQU    PIOB_OER,    0xFFFFF410		// PIOB output
.EQU    PIOB_SODR,   0xFFFFF430		// PIOB set
.EQU    PIOB_CODR,   0xFFFFF434		// PIOB	clear


.section .text
main:
    

        BL      output_init         
	BL	led_on
	BL	led_segm1_on
	BL	led_segm2_on

	LDR     R0, =LED_DECODER
	LDR     R0, [R0]
        LDR     R1, =PIOB_SODR
        STR     R0, [R1]     

	BL	led_clear_all
	
	LDR     R0, =LED_DECODER
	LDR     R0, [R0, #4]
        LDR     R1, =PIOB_SODR
        STR     R0, [R1]     

	BL	led_clear_all

	LDR     R0, =LED_DECODER
	LDR     R0, [R0, #8]
        LDR     R1, =PIOB_SODR
        STR     R0, [R1]     

	BL	led_clear_all

	LDR     R0, =LED_DECODER
	LDR     R0, [R0, #12]
        LDR     R1, =PIOB_SODR
        STR     R0, [R1]     

loop:	
	B	loop


led_on:
        STMFD   SP!, {R0, R1, R2, LR}
        LDR     R0, =0x00010000			// pin 16
        LDR     R1, =PIOB_CODR
        STR     R0, [R1]     
        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR


led_off:
        
        STMFD   SP!, {R0, R1, R2, LR}
        LDR     R0, =0x00010000			// pin 16
        LDR     R1, =PIOB_SODR
        STR     R0, [R1]     
        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR

led_segm1_on:
        STMFD   SP!, {R0, R1, R2, LR}
        LDR     R0, =0x10000000			// pin 16
        LDR     R1, =PIOB_CODR
        STR     R0, [R1]     
        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR


led_segm1_off:
        
        STMFD   SP!, {R0, R1, R2, LR}
        LDR     R0, =0x10000000			// pin 16
        LDR     R1, =PIOB_SODR
        STR     R0, [R1]     
        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR

led_segm2_on:
        STMFD   SP!, {R0, R1, R2, LR}
        LDR     R0, =0x40000000			// pin 16
        LDR     R1, =PIOB_CODR
        STR     R0, [R1]     
        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR


led_segm2_off:
        
        STMFD   SP!, {R0, R1, R2, LR}
        LDR     R0, =0x40000000			// pin 16
        LDR     R1, =PIOB_SODR
        STR     R0, [R1]     
        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR

output_init:
        STMFD   SP!, {R0, R1, R2, LR}

        LDR     R1, =0xFFFFFFFF			// caly port b
        LDR     R2, =PIOB_PER
        STR     R1, [R2]
        LDR     R2, =PIOB_OER
        STR     R1, [R2]
        LDR     R1, =PIOB_CODR			// ustaw zera
        STR     R0, [R1]     

        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR

led_clear_all:
        STMFD   SP!, {R0, R1, R2, LR}
	LDR     R0, =0x0FF00000
        LDR     R1, =PIOB_CODR
        STR     R0, [R1]   
        LDMFD   SP!, {R0, R1, R2, LR}
        BX      LR
	  







.section .data

LED_DECODER: .word 	0x0EE00000
	    .word 	0x07C00000
	    .word 	0x02700000
	    .word 	0x0EE00000
	    .word 	0x0EE00000
	    .word 	0x0EE00000
	    .word 	0x0EE00000
	    .word 	0x0EE00000
