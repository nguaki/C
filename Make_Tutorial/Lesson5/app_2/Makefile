
TGT = app_a

OBJ_DIR = obj

LIB_DIR = ../lib
LIB = gpio
LFLAGS = -l$(LIB) -L$(LIB_DIR)

CC = gcc
CFLAGS = -Wall -std=gnu99 -I$(LIB_DIR)

SRC = $(wildcard *.c)
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.c=.o))

$(TGT): $(OBJ)
	$(CC) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean help run libs

libs:
	cd $(LIB_DIR); \
	$(MAKE) -B; \
	cd -

clean:
	rm -f $(TGT) $(OBJ)
run: $(TGT)
	./$(TGT)


help:
	@echo "SRC $(SRC)"
	@echo "OBJ $(OBJ)"
