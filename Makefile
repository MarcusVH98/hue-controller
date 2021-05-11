CC = gcc
CFLAGS = -O2
CFLAGS += -g
OUTFILE = lights_controller
LINK = -lcurl
LINK += -ljson-c

build:	lights_controller.c
	$(CC) $(LINK) -o $(OUTFILE) $^

clean:
	rm $(OUTFILE)
