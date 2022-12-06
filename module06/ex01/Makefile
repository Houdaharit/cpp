NAME = serialization 

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp serialization.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean: clean

re: fclean all
