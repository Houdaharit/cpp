NAME = megaphone

CC = c++

CFLAGS = -Wall -Wextra -Werror

SRC = megaphone.cpp

all: $(NAME)


$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
