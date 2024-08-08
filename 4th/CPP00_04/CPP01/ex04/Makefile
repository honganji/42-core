NAME := replace

CC := c++
# TODO remove -g flag
CC_FLAG := -Wall -Werror -Wextra -std=c++98 -g

SOURCE := main.cpp replace.cpp

HEADERS := replace.hpp

OBJ_DIR := objs

OBJS := $(SOURCE:%.cpp=$(OBJ_DIR)/%.o)

RM := rm
RM_FLAG := -rf

all: $(NAME)

$(NAME): $(SOURCE) $(OBJ_DIR) $(OBJS)
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
