CC=gcc
CFLAGS=-std=c99 -O0
LDFLAGS=-lcmocka --coverage

batstat: batstat.c
	$(CC) $(CFLAGS)  $^ -o $@


clean:
	rm -f batstat


