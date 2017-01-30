bits 32
section		.text
	align	4
	dd	0x1BADB002
	dd	0x00
	dd	- (0x1BADB002+0x00)

global start
extern kmain		; in kernel.c

start:
	cli		;clear interrupts
	call kmain	; start kernel main function
	hlt		; pause the cpu
