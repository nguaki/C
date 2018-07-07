
LIB = libgpio.a

OBJ_DIR = obj

SRC = $(wildcard *.c)
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.c=.o))

$(LIB): $(OBJ)
	$(AR) cr $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@

.PHONY: help clean run

clean:
	rm -f $(OBJ) $(LIB)

help:
	@echo "SRC: $(SRC)"
	@echo "OBJ: $(OBJ)"
