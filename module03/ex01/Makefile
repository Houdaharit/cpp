NAME = ScavTrap

CC = c++

CFLAGS = -Wall  -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean : clean

re: fclean all
