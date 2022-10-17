NAME = animal

CC = c++

CFLAGS = -Wall -Werror -std=c++98

SRC = main.cpp Brain.cpp Animal.cpp Dog.cpp Cat.cpp

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
