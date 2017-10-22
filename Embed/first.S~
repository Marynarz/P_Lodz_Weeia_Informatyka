.arm
.global main
.equ PIOB_PER, 0xfffff400
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