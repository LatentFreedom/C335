	.text
	.syntax unified
	.thumb
	.global	gcd	
	.type gcd, %function
gcd:
	PUSH {r4-r7}
/*	Your implementation goes here. */
	CMP     r0, r1		@ compare both registers
        BEQ     end		@ if equal then goto end
        BLT     less		@ if r0 less than r1 goto less
        SUBS    r0, r0, r1	@ subtract r1 from r0 and store in r0
        B       gcd
less:	
        SUBS    r1, r1, r0	@ subtract r1 from r0 and store in r1
        B       gcd	
/***************************************/
end:	
	POP {r4-r7}
	BX	lr
