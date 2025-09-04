NAME=Account

CXX = c++
CXXFLAGS =-Wall -Wextra -Werror -std=c++98
SRC = Account.cpp tests.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

run: $(NAME)
	clear
	./Account

clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all