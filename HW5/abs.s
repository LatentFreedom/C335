	.text
	.syntax unified
	.thumb
	.global	abs	
	.type abs, %function
abs:
	push {r4-r7}		// 
/* Your implementation goes here. */
	EORS r4, r4, r7
	SUBS r4, r4, r7
/**********************************/
	pop {r4-r7} 
	bx	lr
