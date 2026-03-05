CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/ticket/ticket.c src/utils/utils.c
OBJ = $(SRC:.c=.o)
TARGET = ticket_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)