CC := gcc
CFLAGS := -g -Wall -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c, obj/%.o, $(SRCS))
TRGT := bin/minesweeper

all: $(TRGT)

$(TRGT): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r bin/* obj/*
