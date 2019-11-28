CC=gcc
CFLAGS=-I. -O3 -march=native -Wall
DEPS=V1933bigCommentFunctions.h V1933bigComment.h V1933paramParser.h
OBJ=V1933bigCommentFunctions.o V1933paramParser.o V1933bigComment.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

V1933bigComment: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
