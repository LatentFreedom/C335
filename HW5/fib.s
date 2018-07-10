        .text
	.syntax unified
        .thumb
	.global fib
        .type fib, %function
fib:
	push {r4-r7}
/* Your implementation goes here. */
	MOVS r1, #1  	@ prev2
	MOVS r2, #1  	@ prev1
	MOVS r3, #1 	@ val
	MOVS r4, #0	@ incrementer
	CMP r0, #0 	@ (r0 == 0)
	BNE else1	@ goto else1 when (r0 != 0)
	MOVS r0, #0	@ r0 = 0
	B end		@ goto end
	
	
else1:	
	CMP r0, #1 	@ (r0 == 1)
	BNE else2	@ goto else2 when (r0 != 1)
	MOVS r0, #1 	@ r0 = 1
	B end 		@ goto end 
else2:
	SUBS r0, r0, #2 @ r0 = r0 - 2
loop:
	CMP r4, r0 	@ (r4 == 0)
	BEQ done	@ goto done when (r4 == 0)
	ADDS r3, r2, r1 @ r3 = r2 + r1
	MOV r1, r2 	@ r1 = r2
	MOV r2, r3 	@ r2 = r3
	ADDS r4, #1 	@ r4 = r4 + 1
	B loop 		@ goto loop 
done:
	MOV r0, r3 	@ r0 = r3
/**********************************/
end:	
        pop {r4-r7}
        bx      lr

	
