TGT = app_2

CC = gcc

######   Library  #######
LIB_DIR = ../lib
LIB_OBJ_DIR = obj
LIB = gpio
LIB_NAME = $(LIB_DIR)/lib$(LIB).a

LIB_SRC = $(wildcard $(LIB_DIR)/*.c)
LIB_OBJ = $(patsubst %, $(LIB_DIR)/$(LIB_OBJ_DIR)/%, $(notdir $(LIB_SRC:.c=.o)))

CFLAGS_LIB = -Wall -std=gnu99

$(LIB_NAME): $(LIB_OBJ)
	$(AR) cr $@ $^
$(LIB_DIR)/$(LIB_OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS_LIB) -c $< -o $@
##### Application ########
OBJ_APP_DIR = obj
SRC_APP = $(wildcard *.c)
OBJ_APP = $(patsubst %, $(OBJ_APP_DIR)/%, $(SRC_APP:.c=.o))

CFLAGS_APP = -Wall -std=gnu99 -I$(LIB_DIR)
LFLAGS_APP = -l$(LIB) -L$(LIB_DIR)

$(TGT):$(OBJ_APP) $(LIB_NAME)
	$(CC) -o $@ $^ $(LFLAGS_APP)

$(OBJ_APP_DIR)/%.o:%.c
	$(CC) $(CFLAGS_APP) -c $< -o $@

.PHONY: help libs_clean clean run
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
