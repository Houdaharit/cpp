NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp commands.cpp 

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
