NAME = form

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp Form.cpp

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -I Form.hpp $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re : fclean all
