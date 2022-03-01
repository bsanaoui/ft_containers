NAME = Containers

CC = clang++
FLAGS = -Werror -Wextra -Wall #-g -fsanitize=address
SRC = main.cpp

all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(SRC) $(FLAG) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :

re : fclean all

push : 
	git add .
	git commit -m "$(m)"
	git push origin