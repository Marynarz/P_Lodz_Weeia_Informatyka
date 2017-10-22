.arm
.global main

.EQU    PIOB_PER,    0xFFFFF400		// PIOB enable
.EQU    PIOB_PDR,    0xFFFFF404		// PIOB disable
.EQU    PIOB_OER,    0xFFFFF410		// PIOB output
.EQU    PIOB_SODR,   0xFFFFF430		// PIOB set
.EQU    PIOB_CODR,   0xFFFFF434		// PIOB	clear

.section .text

port_enable:
  LDR R1,0x1<<8
  LDR R2, = PIOB_PER
  STR R1,[R2]
  MOV PC,LR
main:
  B main
  BL port_enable:
  MOV PC,LR

.end