CFLAGS+=	-W -Wall -std=c99 -g -pedantic
CFLAGS+=	-Iinclude
#CFLAGS+=	-I/usr/local/include
#LDFLAGS+=	-L/usr/local/lib
LDFLAGS+=	-lncurses
LDFLAGS+=	-lpthread

all: main

SRCS= wizard.c
HDRS= wizard.h

main: src/${@}.c ${SRCS:C/.*/src\/&/} ${HDRS:C/.*/include\/&/}
	$(CC) $(CFLAGS) -o bin/$@ src/${@}.c ${SRCS:C/.*/src\/&/} $(LDFLAGS)

pthr2: ${@}.c
	$(CC) $(CFLAGS) ${@}.c $(LDFLAGS) -o bin/$@

.PHONY: clean 
    
clean:
	rm -f *.core *.BAK
	rm -f bin/*

