CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror

.PHONY: clean pack run

tnine: tnine.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -Rf *.o tnine odevzdani.tar.gz

pack:
	tar -czvf odevzdani.tar.gz ./*

run: tnine
	./tnine