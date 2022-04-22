NAME = Containers

CC = clang++
FLAGS = -Werror -Wextra -Wall  -std=c++98
SRC =  main.cpp
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

map_test :
	@$(CC) Tests/map_tests.cpp $(FLAGS) -o $(NAME)
	@./Containers

vector_test :
	@$(CC) Tests/vector_tests.cpp $(FLAGS) -o $(NAME)
	@./Containers

stack_test :
	@$(CC) Tests/stack_tests.cpp $(FLAGS) -o $(NAME)
	@./Containers
