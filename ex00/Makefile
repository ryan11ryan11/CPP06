# SRC = main.cpp HelperFunctions.cpp ScalarConverter.cpp
# OBJ = $(SRC:.cpp=.o)
# CC = c++
# RM = rm -f
# CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g -O0

# NAME = main

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

# %.o: %.cpp
# 	$(CC) $(CPPFLAGS) -c -o $@ $<

# clean:
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean $(NAME)

# .PHONY: all clean fclean re


NAME = main
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3 -O0
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