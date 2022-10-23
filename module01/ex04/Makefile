NAME = replace
 
CC = c++

CFLAGS = -Wall -Wextra -Werror 
SRC = main.cpp replace.cpp

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -fsanitize=address


clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
