BIN:=calculator
BIN_OBJS:=main.o maths.o usage.o
CC:=gcc
CFLAGS:=-Wall -Ipwd
CPPFLAGS := -I$(shell pwd)


PREFIX := /usr

.PHONY: clean all install uninstall
all: $(BIN)

$(BIN): $(BIN_OBJS)
	 $(CC) $(CFLAGS)  -o $@ $^ $(CPPFLAGS)

install:

uninstall:
	
clean:
	$(RM) $(BIN) $(BIN_OBJS)
