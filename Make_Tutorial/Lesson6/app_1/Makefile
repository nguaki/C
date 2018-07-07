######################################################################
#
#  March 7, 17
#
#  This Makefile creates flexibility of separating a shared library
#  to applications.
#
#
#
#
######################################################################
TGT = app_1

CC = gcc
#########################################################################
######                           Library                        #########
#########################################################################

###########################################
#Library path relative to app_1 directory.
###########################################
LIB_DIR = ../lib

###########################################
#Library object
###########################################
LIB_OBJ_DIR = obj

###########################################
#The full name is libgpio.a. 
###########################################
LIB = gpio

###########################################
#Full library name including path.
###########################################
LIB_NAME = $(LIB_DIR)/lib$(LIB).a

###########################################
# Retain all c files for shared library.
###########################################
LIB_SRC = $(wildcard $(LIB_DIR)/*.c)
###########################################
# Retain all object files per c files and attach obj/ directory path.
###########################################
LIB_OBJ = $(patsubst %, $(LIB_DIR)/$(LIB_OBJ_DIR)/%, $(notdir $(LIB_SRC:.c=.o)))

###########################################
#Compilation flag for shared library.
###########################################
CFLAGS_LIB = -Wall -std=gnu99

###########################################
#Shared lib target. Set dependencies to object files.
###########################################
$(LIB_NAME): $(LIB_OBJ)
	$(AR) cr $@ $^
###########################################
# For each object file, the dependency is its corresponding c file.
###########################################
$(LIB_DIR)/$(LIB_OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS_LIB) -c $< -o $@

#########################################################################
#####                          Application                       ########
#########################################################################
OBJ_APP_DIR = obj
SRC_APP = $(wildcard *.c)
OBJ_APP = $(patsubst %, $(OBJ_APP_DIR)/%, $(SRC_APP:.c=.o))

#################################################################
#Note the -I flag which includes directory of header file definition.
#################################################################
CFLAGS_APP = -Wall -std=gnu99 -I$(LIB_DIR)
#################################################################
#Library linking flag.
#    -l flag represents library name. In this case "gpio".
#    -L flag represents library directory.
#################################################################
LFLAGS_APP = -l$(LIB) -L$(LIB_DIR)

#################################################################
#Note that order of -o is important.
#Note that shared library is linked.
#################################################################
$(TGT):$(OBJ_APP) $(LIB_NAME)
	$(CC) -o $@ $^ $(LFLAGS_APP)

#################################################################
#Note that order of -c -o is important.
#################################################################
$(OBJ_APP_DIR)/%.o:%.c
	$(CC) $(CFLAGS_APP) -c $< -o $@

#########################################################################
#####                          Facilities                        ########
#########################################################################
.PHONY: help libs_clean clean run

#########################################################################
# target run has 2 dependencies.
# If a dependency does not exists, it will compile and link.
#########################################################################
run: $(TGT) $(LIB_NAME)
	./$(TGT)

help:
	@echo "lib src: $(LIB_SRC)"
	@echo "lib obj: $(LIB_OBJ)"
	@echo "app src: $(SRC_APP)"
	@echo "app obj: $(OBJ_APP)"

libs_clean:
	rm -f $(LIB_NAME) $(LIB_OBJ)
clean:
	rm -f $(TGT) $(OBJ_APP)
