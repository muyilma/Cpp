NAME=Zombie

CXX = c++
CXXFLAGS =-Wall -Wextra -Werror -std=c++98  
SRC = main.cpp zombieHorde.cpp Zombie.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

run: $(NAME)
	clear
	./$(NAME)

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all