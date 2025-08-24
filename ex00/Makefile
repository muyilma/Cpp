NAME=megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = megaphone.o

all: $(NAME)


$(NAME): $(OBJS)
	c++  -o $(NAME) $(CXXFLAGS) $(OBJS) 

clean:
	rm -rf megaphone.o
	
fclean: clean
	rm -rf $(NAME)

re: fclean all