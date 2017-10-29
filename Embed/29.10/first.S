.arm
.global main
;//zdefiniowanie adresu do piob
.equ PIOB_PER, 0xFFFFF400
.equ PIOB_0ER, 0xFFFFF410
.equ PIOB_0DR, 0xFFFFF414
.equ PIOB_S0DR, 0xFFFFF430
.equ PIOB_C0DR, 0xFFFFF434
.section .text
port_enable:
;//wskazanie gdzie w pamieci ma zapisac zmiane
  LDR R1, = 1<<8
  LDR R2, = PIOB_PER
  LDR R3, = PIOB_0ER
  LDR R4, = PIOB_S0DR
  LDR R5, = PIOB_C0DR
  STR R1,[R2]
  STR R1,[R3]
  STR R1,[R4]
  MOV PC,LR

main:
;//	B main
	BL port_enable
;//powrot do procedury	MOV PC,LR

;//pusta petla
etykieta:
	B etykieta
	
	
.end
