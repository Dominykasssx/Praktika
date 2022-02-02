BIN:=main
BIN_SRCS:=main.c
CC:=gcc
CFLAGS:=-Wall -Ipwd
OBJS:=main.o math_functions.o
CPPFLAGS := -I$(shell pwd)/../lib
LDFLAGS := -L$(shell pwd)/../lib -lmath_functions
PREFIX := /usr

.PHONY: clean all install uninstall
all: $(BIN)

$(BIN): $(BIN_SRCS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

install:
	install -d $(PREFIX)/bin
	install -m 555 $(BIN) $(PREFIX)/bin

uninstall:
	$(RM) $(PREFIX)/bin/$(BIN)
	
clean:
	$(RM) $(BIN) $(OBJS)
