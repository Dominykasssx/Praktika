BIN:=myprog
BIN_OBJS:=main.o

LIB:=libfile_reader.so
LIB_OBJS := file_reader.o

CPPFLAGS := -I$(shell pwd)
LDFLAGS := -L$(shell pwd) -lfile_reader

.PHONY: clean all

all: $(LIB) $(BIN)	

$(LIB):  $(LIB_OBJS)
	$(CC) -fpic -shared -o $@ $^
	
$(BIN): $(BIN_OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS) 
	
clean:
	$(RM) $(LIB) $(BIN) $(BIN_OBJS) $(LIB_OBJS)
