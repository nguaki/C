#Create an object file and put the obj file in its directory. Read include file from a 
#include directory.  -fPIC is position-independent code.  This is needed for dynamic library.
#
#
#Treadmill for US, 
#   (1)comment out line for hfcal_uk.c
#   (2)'make hfcal.o' and 'make '
#   (3)'make libhfcal.so'
#
#Treadmill for UK,
#   (1)comment out line for hfcal.c
#   (2)'make hfcal.o' and 'make '
#   (3)'make libhfcal.so'
#

#hfcal.o: hfcal.c
#	gcc -Iinclude_files/ -fPIC -c hfcal.c -o object_files/hfcal.o

hfcal.o: hfcal_uk.c
	gcc -Iinclude_files/ -fPIC -c hfcal_uk.c -o object_files/hfcal.o

#Create an object file and put the obj file in its directory. Read include file from a 
#include directory.
elliptical.o: elliptical.c
	gcc -Iinclude_files/ -c elliptical.c -o object_files/elliptical.o
	
#Create a dynamic library.
libhfcal.so: hfcal.o
	gcc -shared object_files/hfcal.o -o libs/libhfcal.so
	
elliptical: elliptical.o libhfcal.so
	gcc object_files/elliptical.o -Iinclude_files/ -Llibs -lhfcal -o elliptical