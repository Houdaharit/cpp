NAME= convert

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp parsing.cpp convert.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean: clean

re: fclean all
