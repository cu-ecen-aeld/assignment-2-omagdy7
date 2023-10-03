CC := gcc
CROSS_COMPILE ?=

# Native build configuration
ifeq ($(CROSS_COMPILE),)
    TARGET := writer
else
    CC := $(CROSS_COMPILE)gcc
    TARGET := writer
endif

SRCS := writer.c
OBJS := $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
