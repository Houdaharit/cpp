NAME = diamondtrap

CC = c++

CFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

SRC = main.cpp FragTrap.cpp ClapTrap.cpp ScavTrap.cpp DiamondTrap.cpp

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re: fclean all
