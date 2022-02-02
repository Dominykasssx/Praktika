SRC := $(wildcard *.c)
BINS := $(SRC:.c=)

.PHONY: all clean

all: $(BINS)

%: %.c
	$(CC) -w -o $@ $^

clean:
	$(RM) $(BINS)