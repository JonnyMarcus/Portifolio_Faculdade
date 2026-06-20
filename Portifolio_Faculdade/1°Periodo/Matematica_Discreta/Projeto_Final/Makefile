CC = gcc
FLAGS = -I./includes
SRCS = src/main.c src/conjunto.c src/grafo.c src/hitorico.c src/relacoes.c src/utils.c
TARGET = matematica_discreta

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(FLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)