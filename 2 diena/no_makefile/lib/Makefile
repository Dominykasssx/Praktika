BIN:=myprog
BIN_SRCS:=main.o

LIB:=libfile_reader.so
LIB_SRCS := file_reader.o

CPPFLAGS := -I$(shell pwd)/
LDFLAGS := -L$(shell pwd)/ -lfile_reader
CC:=gcc

.PHONY: clean all

all: $(LIB) $(BIN)	

$(LIB):  $(LIB_SRCS)
	$(CC) -fpic -shared -o $@ $^
	
$(BIN): $(BIN_SRCS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS) 
	
clean:
	$(RM) $(LIB) $(BIN) $(BIN_SRCS) $(LIB_SRCS)
