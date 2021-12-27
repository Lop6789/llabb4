CC=gcc

CFLAGS=-c -Wall -std=c99

LDFLAGS=-lreadline -lm

SRCS=main.c inp.c edit.c check.c chooser.c mystr.c output.c sort.c QuickSort.c 

OBJS=$(SRCS:.c=.o)

EXE=lab4

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(EXE)
		
