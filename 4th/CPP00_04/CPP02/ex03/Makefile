NAME := canonical_form

CC := c++
CC_FLAG := -Wall -Werror -Wextra -std=c++98

SOURCE := main.cpp Fixed.cpp Point.cpp bsp.cpp

HEADERS := Fixed.hpp Point.hpp

OBJ_DIR := objs

OBJS := $(SOURCE:%.cpp=$(OBJ_DIR)/%.o)

RM := rm
RM_FLAG := -rf

all: $(NAME)

$(NAME): $(SOURCE) $(OBJ_DIR) $(OBJS) $(HEADERS)
	$(CC) $(CC_FLAG) $(OBJS) -o $(NAME)


$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CC_FLAG) -c $< -o $@

clean: 
	$(RM) $(RM_FLAG) $(OBJ_DIR)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

.PHONY: all clean fclean re
