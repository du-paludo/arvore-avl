flags = -Wall -std=c99
nome = myavl

all: $(nome)

$(nome): main.o libavl.o
	gcc -o $(nome) main.o libavl.o $(flags)

main.o: main.c
	gcc -c main.c $(flags)

libavl.o: libavl.c
	gcc -c libavl.c $(flags)

clean:
	rm -f *~ *.o

purge: clean
	rm -f $(nome)