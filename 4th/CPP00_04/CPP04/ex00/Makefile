NAME := animal
SOURCE := main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

HEADER := Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

OBJ_DIR := objs

OBJS := $(SOURCE:%.cpp=$(OBJ_DIR)/%.o)

CC := c++
CC_FLAG := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SOURCE) $(OBJ_DIR) $(OBJS) $(HEADER)
	$(CC) $(CC_FLAG) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
