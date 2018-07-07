#######################################################
###              APP                                ###
#######################################################

########################################
#define executable name
########################################
TGT = app_a

########################################
#Directory for OBJ
########################################
OBJ_DIR = obj

########################################
#shared lib directory
########################################
LIB_DIR = ../lib

########################################
#Identify shared lib name
########################################
LIB = gpio

########################################
# Here are library related flags when linking
#      -l  flag for specific libray name
#      -L  specifies library directory
########################################
LFLAGS = -l$(LIB) -L$(LIB_DIR)

CC = gcc

########################################
#By identifying LIB_DIR, all includes can have #include <>.
#   -I flag is to include all directories.
########################################
CFLAGS = -Wall -std=gnu99 -I$(LIB_DIR)

########################################
# SRC retains all file names.
########################################
SRC = $(wildcard *.c)

########################################
# OBJ retains all object file names with
# directory prefix.
# e.g.      obj/relay.o
########################################
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.c=.o))

########################################
#Link with library flags
########################################
$(TGT): $(OBJ)
	$(CC) -o $@ $^ $(LFLAGS)

########################################
#Compile with  cflags.
#Remember -c flag.
########################################
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
	
#######################################################
###              UTILITY  TOOLS                     ###
#######################################################
.PHONY: clean help run libs

#######################################################
# Builds shared library.
# 
# Steps taken:
#       Navigates to lib directory.
#       Executes make
#       Returns back to this directory.
#######################################################
libs:
	cd $(LIB_DIR); \
	$(MAKE) -B; \
	cd -

clean:
	rm -f $(TGT) $(OBJ)
	
#######################################################
# This will execute.
# It will build the target if it doesn't exists.
#######################################################
run: $(TGT)
	./$(TGT)

#######################################################
# Great debugging tool.
#######################################################
help:
	@echo "SRC $(SRC)"
	@echo "OBJ $(OBJ)"
