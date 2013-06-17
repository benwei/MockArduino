CFILES=main.c sounds.c
OBJS=$(CFILES:.c=.o)

CFLAGS=-g -I.
LDFLAGS=

all: mock_arduino
.c.o:
	gcc -c $< -o $@ $(CFLAGS)

mock_arduino: $(OBJS)
	gcc -o $@  $^ $(LDFLAGS)

run: mock_arduino
	./mock_arduino

clean:
	rm -f *.o mock_arduino
