CC = /usr/bin/gcc
CFLAGS = -Wall

OBJ = v24.o transfer.o crc.o fileio.o 
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
	find . -maxdepth 1 -type f  ! -name 'fileio.o' -name '*.o' -execdir rm {} +
	rm -f $(BIN)
