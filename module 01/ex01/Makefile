NAME = zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRC = Zombie.cpp zombieHorde.cpp main.cpp

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
