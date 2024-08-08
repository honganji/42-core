NAME := libftprintf.a

SOURCES := ft_printf.c put_some.c

# TEST
TEST_SOURCE := main.c $(NAME)

OBJS := $(SOURCES:%.c=%.o)

CC := cc
AR := ar
RM := rm

AR_FLAG := -rcs
CC_FLAG := -Wall -Wextra -Werror
RM_FLAG := -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AR_FLAG) $(NAME) $(OBJS)

clean:
	$(RM) $(RM_FLAG) $(OBJS)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

# TEST
exe:
	$(CC) $(CC_FLAG) $(TEST_SOURCE) -o main
	./main

%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

PHONY: all clean fclean re