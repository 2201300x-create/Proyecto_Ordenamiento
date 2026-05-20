<<<<<<< HEAD
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
=======
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
>>>>>>> 4da7289b6b90241c3e623e771430cd8791e88de2
