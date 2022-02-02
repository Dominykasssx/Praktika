BIN:=calculator
BIN_SRCS:=main.o maths.o usage.o
CC:=gcc
CFLAGS:=-Wall -Ipwd
CPPFLAGS := -I$(shell pwd)/


PREFIX := /usr

.PHONY: clean all install uninstall
all: $(BIN)

$(BIN): $(BIN_SRCS)
	 $(CC) $(CFLAGS)  -o $@ $^ $(CPPFLAGS)

install:

uninstall:
	
clean:
	$(RM) $(BIN) $(BIN_SRCS)
