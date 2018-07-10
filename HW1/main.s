	.cpu cortex-m0
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.code	16
	.file	"test.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.bss
	.align	2
state:
	.space	4
	.section	.rodata
	.align	2
.LC1:
	.ascii	"RED\000"
	.align	2
.LC4:
	.ascii	"GREEN\000"
	.align	2
.LC6:
	.ascii	"YELLOW\000"
	.text
	.align	2
	.global	stop_light
	.code	16
	.thumb_func
	.type	stop_light, %function
stop_light:
.LFB0:
	.file 1 "test.c"
	.loc 1 12 0
	.cfi_startproc
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	.loc 1 15 0
	ldr	r3, .L11
	ldr	r3, [r3]
	cmp	r3, #1
	beq	.L3
	cmp	r3, #2
	beq	.L4
	cmp	r3, #0
	bne	.L10
	.loc 1 17 0
	ldr	r3, .L11+4
	mov	r0, r3
	bl	puts
	.loc 1 18 0
	ldr	r3, .L11+8
	ldr	r3, [r3]
	add	r2, r3, #1
	ldr	r3, .L11+8
	str	r2, [r3]
	ldr	r3, .L11+8
	ldr	r3, [r3]
	cmp	r3, #4
	ble	.L6
	.loc 1 19 0
	ldr	r3, .L11+8
	mov	r2, #0
	str	r2, [r3]
	.loc 1 20 0
	ldr	r3, .L11
	mov	r2, #2
	str	r2, [r3]
	.loc 1 22 0
	b	.L1
.L6:
	b	.L1
.L4:
	.loc 1 25 0
	ldr	r3, .L11+12
	mov	r0, r3
	bl	puts
	.loc 1 26 0
	ldr	r3, .L11+8
	ldr	r3, [r3]
	add	r2, r3, #1
	ldr	r3, .L11+8
	str	r2, [r3]
	ldr	r3, .L11+8
	ldr	r3, [r3]
	cmp	r3, #4
	ble	.L8
	.loc 1 27 0
	ldr	r3, .L11+8
	mov	r2, #0
	str	r2, [r3]
	.loc 1 28 0
	ldr	r3, .L11
	mov	r2, #1
	str	r2, [r3]
	.loc 1 30 0
	b	.L1
.L8:
	b	.L1
.L3:
	.loc 1 33 0
	ldr	r3, .L11+16
	mov	r0, r3
	bl	puts
	.loc 1 34 0
	ldr	r3, .L11+8
	ldr	r3, [r3]
	add	r2, r3, #1
	ldr	r3, .L11+8
	str	r2, [r3]
	ldr	r3, .L11+8
	ldr	r3, [r3]
	cmp	r3, #1
	ble	.L9
	.loc 1 35 0
	ldr	r3, .L11+8
	mov	r2, #0
	str	r2, [r3]
	.loc 1 36 0
	ldr	r3, .L11
	mov	r2, #0
	str	r2, [r3]
	.loc 1 38 0
	b	.L1
.L9:
	b	.L1
.L10:
	.loc 1 41 0
	ldr	r3, .L11
	mov	r2, #0
	str	r2, [r3]
	.loc 1 42 0
	ldr	r3, .L11+8
	mov	r2, #0
	str	r2, [r3]
	.loc 1 43 0
	mov	r8, r8
.L1:
	.loc 1 45 0
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
.L12:
	.align	2
.L11:
	.word	state
	.word	.LC1
	.word	state_counter.4968
	.word	.LC4
	.word	.LC6
	.cfi_endproc
.LFE0:
	.size	stop_light, .-stop_light
	.align	2
	.global	main
	.code	16
	.thumb_func
	.type	main, %function
main:
.LFB1:
	.loc 1 47 0
	.cfi_startproc
	push	{r7, lr}
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	.cfi_offset 14, -4
	sub	sp, sp, #8
	.cfi_def_cfa_offset 16
	add	r7, sp, #0
	.cfi_def_cfa_register 7
	.loc 1 50 0
	b	.L14
.L15:
	.loc 1 51 0
	bl	stop_light
	.loc 1 52 0
	ldr	r3, [r7, #4]
	mov	r0, r3
	bl	inc
	mov	r3, r0
	str	r3, [r7, #4]
.L14:
	.loc 1 50 0 discriminator 1
	ldr	r3, [r7, #4]
	cmp	r3, #35
	ble	.L15
	.loc 1 54 0
	mov	r0, r3
	mov	sp, r7
	add	sp, sp, #8
	@ sp needed
	pop	{r7, pc}
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.bss
	.align	2
state_counter.4968:
	.space	4
	.text
.Letext0:
	.section	.debug_info,"",%progbits
.Ldebug_info0:
	.4byte	0xf3
	.2byte	0x4
	.4byte	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	.LASF15
	.byte	0x1
	.4byte	.LASF16
	.4byte	.LASF17
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	.LASF1
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	.LASF3
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	.LASF4
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	.LASF5
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	.LASF8
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	.LASF9
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	.LASF10
	.uleb128 0x4
	.4byte	.LASF18
	.byte	0x1
	.byte	0x1
	.byte	0x9
	.4byte	0x98
	.uleb128 0x5
	.ascii	"RED\000"
	.sleb128 0
	.uleb128 0x6
	.4byte	.LASF11
	.sleb128 1
	.uleb128 0x6
	.4byte	.LASF12
	.sleb128 2
	.byte	0
	.uleb128 0x7
	.4byte	.LASF19
	.byte	0x1
	.byte	0xc
	.4byte	.LFB0
	.4byte	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xbf
	.uleb128 0x8
	.4byte	.LASF13
	.byte	0x1
	.byte	0xd
	.4byte	0x2c
	.uleb128 0x5
	.byte	0x3
	.4byte	state_counter.4968
	.byte	0
	.uleb128 0x9
	.4byte	.LASF20
	.byte	0x1
	.byte	0x2f
	.4byte	0x2c
	.4byte	.LFB1
	.4byte	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xe5
	.uleb128 0xa
	.ascii	"i\000"
	.byte	0x1
	.byte	0x30
	.4byte	0x2c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -12
	.byte	0
	.uleb128 0x8
	.4byte	.LASF14
	.byte	0x1
	.byte	0xa
	.4byte	0x2c
	.uleb128 0x5
	.byte	0x3
	.4byte	state
	.byte	0
	.section	.debug_abbrev,"",%progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",%progbits
	.4byte	0x1c
	.2byte	0x2
	.4byte	.Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	.Ltext0
	.4byte	.Letext0-.Ltext0
	.4byte	0
	.4byte	0
	.section	.debug_line,"",%progbits
.Ldebug_line0:
	.section	.debug_str,"MS",%progbits,1
.LASF7:
	.ascii	"long long int\000"
.LASF0:
	.ascii	"unsigned int\000"
.LASF20:
	.ascii	"main\000"
.LASF18:
	.ascii	"light_states\000"
.LASF6:
	.ascii	"long unsigned int\000"
.LASF8:
	.ascii	"long long unsigned int\000"
.LASF13:
	.ascii	"state_counter\000"
.LASF2:
	.ascii	"unsigned char\000"
.LASF12:
	.ascii	"GREEN\000"
.LASF10:
	.ascii	"char\000"
.LASF16:
	.ascii	"test.c\000"
.LASF5:
	.ascii	"long int\000"
.LASF19:
	.ascii	"stop_light\000"
.LASF11:
	.ascii	"YELLOW\000"
.LASF17:
	.ascii	"/nfs/nfs4/home/npalumbo/c335-submissions/HW1\000"
.LASF15:
	.ascii	"GNU C 4.8.4 20140526 (release) [ARM/embedded-4_8-br"
	.ascii	"anch revision 211358] -mcpu=cortex-m0 -mthumb -g\000"
.LASF4:
	.ascii	"short unsigned int\000"
.LASF1:
	.ascii	"signed char\000"
.LASF14:
	.ascii	"state\000"
.LASF3:
	.ascii	"short int\000"
.LASF9:
	.ascii	"sizetype\000"
	.ident	"GCC: (GNU Tools for ARM Embedded Processors) 4.8.4 20140526 (release) [ARM/embedded-4_8-branch revision 211358]"
