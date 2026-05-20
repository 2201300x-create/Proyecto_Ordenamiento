CC = gcc
CFLAGS = -Wall -O2

SRC = src/main.c src/algoritmos.c src/datasets.c

OUT = benchmark

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) -lm

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
