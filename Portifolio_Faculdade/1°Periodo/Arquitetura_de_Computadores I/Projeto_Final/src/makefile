CC = gcc
TARGET = simulador

all: $(TARGET)

$(TARGET): main.c conversao.c
	$(CC) main.c conversao.c -o $(TARGET)

clean:
	rm -f $(TARGET)