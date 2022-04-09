NAME = Containers

CC = clang++
FLAGS = -Werror -Wextra -Wall -std=c++98  #-g -fsanitize=address
SRC_TEST =   Tests/map_tests.cpp
SRC =   main.cpp
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

test : 
	@$(CC) $(SRC_TEST) $(FLAGS) -o $(NAME)
	@./Containers

test_san : 
	@$(CC) $(SRC_TEST) $(FLAGS) -g -fsanitize=address -o $(NAME)
	@./Containers
