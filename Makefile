NAME = Containers

CC = clang++
FLAGS = -Werror -Wextra -Wall  #-std=c++98 -g -fsanitize=address
SRC =   Tests/map_tests.cpp
# SRC =   main.cpp
all : $(NAME)

$(NAME) : $(SRC)
	@$(CC) $(SRC) $(FLAGS) -o $(NAME)

fclean : clean
	@rm -f $(NAME)

clean :

re : fclean all

push : 
	git add .
	git commit -m "$(m)"
	git push origin