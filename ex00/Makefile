NAME = main
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp HelperFunctions.cpp ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

# CRITICAL: -g must be here during linking
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

# CRITICAL: -g must be here during compilation
%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
