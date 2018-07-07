TARGET1 = main1
TARGET2 = main2

$(TARGET1): main1.o
	gcc main1.o -o $@

$(TARGET2): main2.o
	gcc main2.o -o $@

%.o: %.c
	gcc -c $< -o $@

run1: $(TARGET1)
	./$(TARGET1)

run2: $(TARGET2)
	./$(TARGET2)

all: $(TARGET1) $(TARGET2)
	./$(TARGET1)
	./$(TARGET2) 
