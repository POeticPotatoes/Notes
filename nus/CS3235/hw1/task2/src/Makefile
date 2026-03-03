SOURCES=main.c
LDFLAGS:=-z relro -z now -z noexecstack
CFLAGS:=-m32 -Wall -no-pie -fno-stack-protector
TARGET:=../challenge
CC:=gcc

.PHONY: all clean $(TARGET)

all: $(TARGET)

clean:
	rm -f $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(CFLAGS) $(SOURCES) $(LDFLAGS)
