#Create an object file and put the obj file in its directory. Read include file from a 
#include directory.
encrypt.o: encrypt.c
	gcc -Iinclude_files/ -c encrypt.c -o object_files/encrypt.o

#Create an object file and put the obj file in its directory. Read include file from a 
#include directory.
checksum.o: checksum.c
	gcc -Iinclude_files/ -c checksum.c -o object_files/checksum.o
	
#Create an executable from obj files.
test_code: encrypt.o checksum.o
	gcc -Iinclude_files test_code.c object_files/encrypt.o object_files/checksum.o -o test_code
	
libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a object_files/encrypt.o object_files/checksum.o
	
test_code1: test_code.c libhfsecurity.a
	gcc test_code.c -Iinclude_files/ -L. -lhfsecurity -o test_code1