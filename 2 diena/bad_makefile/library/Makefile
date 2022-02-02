CC:=gcc
CFLAGS:=-Wall
LIB:=libmath_functions.so
LIB_SRCS := math_functions.c
PREFIX := /usr

.PHONY: clean all install uninstall

all: $(LIB)	

$(LIB):  $(LIB_SRCS)
	$(CC) -fpic -shared -o $@ $^

install: $(LIB)
	install -d $(PREFIX)/lib $(PREFIX)/include
	install -m 644 $(LIB) $(PREFIX)/lib
	install -m 644 math_functions.h $(PREFIX)/include

uninstall:
	$(RM) $(PREFIX)/lib/$(LIB)
	$(RM) $(PREFIX)/include/math_functions.h
clean:
	$(RM) $(LIB)
