.section .init
.glboal _init
.type _init, @function
_init:
    push %ebp
    movl %esp, %ebp
    # gcc put ctrbegin.o .init seciton here

.section .fini
.global _fini
.type _fini, @function
_fini:
    push %ebp
    movl %esp, %ebp
    # gcc put ctrbegin.o .fini here 