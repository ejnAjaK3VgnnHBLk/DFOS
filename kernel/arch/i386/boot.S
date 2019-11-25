# Multiboot header constants
.set ALIGN, 1<<0
.set MEMINFO, 1<<1
.set FLAGS, ALIGN | MEMINFO
.set MAGIC, 0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

# Declare header as per multiboot standard
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Make stack for initial thread
.section .bss
.align 16
stack_bottom:
.skip 16384   # 16KiB
stack_top:

# Kernel entry point
.section .text
.global _start
.type _start, @function
_start:
    movl $stack_top, %esp

    # Call global constructors
    call _init

    # Control now goes to main Kernel
    call kernel_main

    # hang if kernel  retuns something on accident
    cli
1:  hlt
    jmp 1b
.size _start, . - _start