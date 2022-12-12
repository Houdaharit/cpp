NAME= real_type

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Base.cpp realType.cpp A.cpp C.cpp B.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
