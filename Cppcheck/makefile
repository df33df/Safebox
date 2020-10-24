
main: authenticate.o main.o
	clang authenticate.o main.o -o main -Weverything -lncurses

authenticate.o: authenticate.c
	clang -c authenticate.c -o authenticate.o -Weverything -lncurses

main.o: main.c authenticate.h
	clang -c main.c -o main.o -Weverything -lncurses

clean:
	rm -rf *.o
	rm main
