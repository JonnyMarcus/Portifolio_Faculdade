CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99
LIBS    = -lm

TARGET  = simulador
SRCS    = main.c conversoes.c memoria.c utils.c
OBJS    = $(SRCS:.c=.o)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o:       main.c conversoes.h memoria.h utils.h
conversoes.o: conversoes.c conversoes.h
memoria.o:    memoria.c memoria.h conversoes.h
utils.o:      utils.c utils.h


run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild