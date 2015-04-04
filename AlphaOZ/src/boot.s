global _loader		; esto es para el linkeo
global eokl		; punto final del kernel
extern k_main
 
; setting up the Multiboot header - see GRUB docs for details
; no tocar, es para que arranque el GRUB
MODULEALIGN equ  1<<0                   ; align loaded modules on page boundaries
MEMINFO     equ  1<<1                   ; provide memory map
FLAGS       equ  MODULEALIGN | MEMINFO  ; this is the Multiboot 'flag' field
MAGIC       equ    0x1BADB002           ; 'magic number' lets bootloader find the header
CHECKSUM    equ -(MAGIC + FLAGS)        ; checksum required
 
section .text
align 4
MultiBootHeader:
	dd MAGIC
	dd FLAGS
	dd CHECKSUM
 
	; reservar stack
	STACKSIZE equ 0x4000		; 16k
	_loader:
	mov esp, stack+STACKSIZE; set up the stack
	push eax		; pasamos Multiboot Magick Number
	push ebx		; pasamos Multiboot Info Structure
	call k_main
	hlt
 
eokl	dd STACKSIZE + stack
	section .bss
	align 32
	stack:
	resb STACKSIZE		; reservar 16k de stack en una quadword?