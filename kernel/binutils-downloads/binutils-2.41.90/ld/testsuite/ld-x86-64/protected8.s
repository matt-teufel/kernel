	.protected	foo
.globl foo
	.data
	.align 4
	.type	foo, @object
	.size	foo, 4
foo:
	.long	1
	.text
.globl bar
	.type	bar, @function
bar:
	movl	foo(%rip), %eax
	ret
	.size	bar, .-bar

	.section ".note.gnu.property", "a"
	.p2align 3
	.long 1f - 0f		/* name length.  */
	.long 3f - 2f		/* data length.  */
	/* NT_GNU_PROPERTY_TYPE_0 */
	.long 5			/* note type.  */
0:	.asciz "GNU"		/* vendor name.  */
1:
	.p2align 3
2:
	/* GNU_PROPERTY_NO_COPY_ON_PROTECTED */
	.long 2			/* pr_type.  */
	.long 0			/* pr_datasz.  */
	.p2align 3
3:
