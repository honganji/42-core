NAME := philo

UTILS_DIR := utils
THREAD_DIR := thread

SOURCE := main.c \
		  $(addprefix $(UTILS_DIR)/, store_input.c ft_atoi.c ft_isnum.c \
		  ft_split.c initialize.c ft_get_current_time.c check_num.c \
		  clean_data.c ft_usleep.c store_input_utils.c error.c) \
		  $(addprefix $(THREAD_DIR)/, setup_philo.c setup_monitor.c )

OBJ_DIR := objs
OBJ_DIR_COLLECTION := objs \
					  $(addprefix $(OBJ_DIR)/, $(UTILS_DIR) $(THREAD_DIR))

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

CC := cc
MAKEDIR := mkdir
RM := rm

CC_FLAG := -Wall -Werror -Wextra
RM_FLAG := -rf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(SOURCE)
	$(CC) $(CC_FLAG) $(OBJS) -o $@

clean:
	$(RM) $(RM_FLAG) $(OBJ_DIR)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

$(OBJ_DIR):
	$(MAKEDIR) $(OBJ_DIR_COLLECTION)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

exe: $(NAME)
	./$< 3 310 200 100

.PHONY: all clean fclean re
