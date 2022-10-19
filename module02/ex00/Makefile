NAME = fixed

CC = c++ 

CFLAGS = -Wall -Wextra -Wall -std=c++98

SRC = main.cpp Fixed.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
