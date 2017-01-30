
nasm -f elf32 ../kernel/bootload.s -o  ../obj/bootload.o 
gcc -m32 -c -I./.. ../kernel/console.c -o ../obj/console.o
gcc -m32 -c -I./.. ../kernel/string.c -o ../obj/string.o
#gcc -m32 -c -I./.. ../kernel/inlinerasm.c -o ../obj/inlinerasm.o
gcc -m32 -c -I./.. ../kernel/kernel.c -o ../obj/kernel.o
ld -m elf_i386 -T link.ld -o ../bin/kernel.bin ../obj/bootload.o ../obj/console.o ../obj/inlinerasm.o ../obj/string.o ../obj/kernel.o
qemu-system-i386 -kernel ../bin/kernel.bin
