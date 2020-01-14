CFLAGS+=	-W -Wall -std=c99 -g -pedantic
#CFLAGS+=	-I/usr/local/include
#LDFLAGS+=	-L/usr/local/lib
LDFLAGS+=	-lncurses

all: main

main: ${@}.c
	$(CC) $(CFLAGS) ${@}.c $(LDFLAGS) -o $@


.PHONY: clean 
    
clean:
	rm -f main *.core *.BAK

