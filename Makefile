CC = clang
CFLAGS = -Wall -Wextra -g

TARGET = ReadMeTxt
SOURCE = ReadMeTxt.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

.PHONY: clean
clean:
	rm -f $(TARGET)
