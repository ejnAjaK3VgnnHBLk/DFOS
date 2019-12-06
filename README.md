# DFOS
DFOS

We are using an i686-elf cross compiler. To set this up, set your $PREFIX to cross compiler installation directory, $TARGET to i686-elf, and $PATH to $PREFIX/bin:$PATH. Obtain the Binutils and GCC source, and compile both of those using the provided flags. To use the compiler, $PREFIX/bin/$TARGET-gcc, or add it to your path.

To build and run, just run the qemu.sh script. Make sure to have all of the build tools installed and QEMU as well for the virtualization environment. You can search around for pre-compiled i686-elf compilers if you are lacking computing power.

The libc library right now will be completely rewritten in the new future. It is being used now for debugging purposes and to test features. 
