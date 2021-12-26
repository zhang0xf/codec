#指定编译器选项
CC = gcc	
WORKDIR = .
CFLAGS = -Wall -g
INCFLAG = -I$(WORKDIR)/codec
SRCDIR = $(WORKDIR)/codec

SRCS = $(wildcard $(SRCDIR)/*.c)
NODIR_SRCS = $(notdir $(SRCS))
OBJS = $(patsubst %.c, %.o, $(NODIR_SRCS))

BIN = main

$(BIN):$(OBJS)
	$(CC) $^ -o $@
	@mv $(WORKDIR)/*.o $(SRCDIR)

%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

.PHONY:clean

clean:
	rm $(WORKDIR)/$(BIN) $(SRCDIR)/*.o