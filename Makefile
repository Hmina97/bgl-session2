CC=clang
CFLAGS=-std=c99 -O0
LDFLAGS=-lcmocka 

batstat: batstat.c
	$(CC) $(CFLAGS)  $^ -o $@


test_batstat: test_batstat.c batstat.c 
	$(CC) $(CFLAGS)  $^ -o $@

clean:
	rm -f batstat test_batstat


