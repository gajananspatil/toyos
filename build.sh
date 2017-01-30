
nasm -f elf32 kernel/bootload.s -o  obj/bootload.o
gcc -m32 -c kernel/kernel.c -o obj/kernel.o
ld -m elf_i386 -T link.ld -o boot/kernel.bin obj/bootload.o obj/kernel.o
qemu-system-i386 -kernel boot/kernel.bin
