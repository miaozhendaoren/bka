CC = /usr/bin/gcc
CFLAGS = -Wall

OBJ = fileio.o v24.o crc.o
BIN = Serial

Serial: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

s: $(BIN)
	./Serial s

r: $(BIN)
	./Serial r

clean:
	rm -rf $(BIN) v24.o crc.o
