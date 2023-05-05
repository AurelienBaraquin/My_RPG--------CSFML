##
## EPITECH PROJECT, 2023
## My_rpg
## File description:
## Makefile
##

CFLAGS = 	-W -Wall -Wextra -lm -lcsfml-graphics -lcsfml-window\
			-lcsfml-system -lcsfml-audio
CPPFLAGS = 	-Iinclude

SRC =		$(shell find src -name "*.c")
OBJ = 		$(SRC:.c=.o)
TARGET = 	my_rpg

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(TARGET)

re: fclean all
