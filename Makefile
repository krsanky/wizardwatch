CFLAGS+=	-W -Wall -std=c99 -g -pedantic
#CFLAGS+=	-I/usr/local/include
#LDFLAGS+=	-L/usr/local/lib
LDFLAGS+=	-lncurses
LDFLAGS+=	-lpthread

all: main ww

main: ${@}.c
	$(CC) $(CFLAGS) ${@}.c $(LDFLAGS) -o $@

ww: ${@}.c
	$(CC) $(CFLAGS) ${@}.c $(LDFLAGS) -o $@

.PHONY: clean 
    
clean:
	rm -f main *.core *.BAK
	rm -f ww

