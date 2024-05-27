CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = 
SRCS = src/main.c src/input.c src/simulate.c src/output.c
OBJS = $(SRCS:.c=.o)
EXEC = hashcode

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
