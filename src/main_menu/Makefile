##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## RPG
##

CC = gcc
CFLAGS = -W -Wextra -Wall

SRC =	main.c\
		init.c\
		init_bars.c\
		source.c\
		source2.c\
		events.c\
		display.c\
		init_sets_bar.c\
		init_sets_bar2.c\
		clic_events.c

OBJ = $(SRC:.c=.o)

LIB = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

TARGET =	menu

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LIB)

all: $(TARGET)

clean:
	$(RM) -f $(OBJ)

fclean : clean
	$(RM) $(TARGET)

re: fclean all
