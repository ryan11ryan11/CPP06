# NAME = main
# CC = c++
# CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3 -O0
# SRC = main.cpp Serializer.cpp Serializer.hpp
# OBJ = $(SRC:.cpp=.o)

# all: $(NAME)

# # CRITICAL: -g must be here during linking
# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

# # CRITICAL: -g must be here during compilation
# %.o: %.cpp
# 	$(CC) $(CPPFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re




NAME = main.exe
CC = g++
# Using gnu++98 to bypass MinGW 6.3.0 header bugs while maintaining C++98 compatibility 
CPPFLAGS = -Wall -Wextra -Werror -std=gnu++98 -pedantic -g3 -O0
SRC = main.cpp Base.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

# Windows-compatible cleanup using 'del'
clean:
	@if exist *.o del /f /q *.o

fclean: clean
	@if exist $(NAME) del /f /q $(NAME)

re: fclean all

.PHONY: all clean fclean re