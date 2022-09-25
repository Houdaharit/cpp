NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRC = main.cpp commands.cpp 

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
