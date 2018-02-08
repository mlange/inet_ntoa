CC=c89

main: main.o
	$(CC) main.o -lmalloc -lc -lnsl -o main

clean:
	-@rm -f main
	-@rm -f main.o 
