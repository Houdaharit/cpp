NAME = brain

CC = c++

CFLAGS = -Wall -Wextra -Werror - std=c++98

SRC = Animal.cpp Dog.cpp Cat.cpp Brain.cpp

all : $(NAME)

$(SRC) : $(NAME)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
