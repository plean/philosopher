CC	= gcc

CFLAGS	+= -W -Wall -Wextra -Iinclude -g3
LDFLAGS += -L lib -lriceferee -lpthread

SRC	= $(addprefix src/, \
	  	main.c \
		philo.c)

OBJ	= $(SRC:.c=.o)

NAME	= philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
