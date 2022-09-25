NAME= zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean: clean

re: fclean all
