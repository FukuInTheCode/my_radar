##
## EPITECH PROJECT, 2023
## settingup Makefile
## File description:
## Placeholder
##

NAME   = my_radar

CC	   = gcc

CFLAGS = -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
	-Wno-unused-parameter -I./include -g -std=c99 -lm -lc

CSFML = -lcsfml-system -lcsfml-window -lcsfml-network \
			-lcsfml-graphics -lcsfml-audio

CRITERION = -lcriterion

SRC	= src/my_radar.c \
	  src/my_strncmp.c \
	  src/my_strlen.c \
	  src/radar_file.c \
	  src/radar_usage.c \
	  src/radar_loop.c \
	  src/handle_events.c \
	  src/plane_draw.c \
	  src/plane_update.c \
	  src/my_getnbr.c \
	  src/my_str_to_word_array.c \
	  src/my_strdup.c \
	  src/my_strcpy.c \
	  src/my_strcmp.c \
	  src/handle_close.c \
	  src/plane_add.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML) \
	$(CRITERION)
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
