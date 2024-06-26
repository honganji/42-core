NAME = client
NAME_SERVER = server
NAME_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

CLIENT_HEADER = $(CLIENT_DIR)/client.h
SERVER_HEADER = $(SERVER_DIR)/server.h

CLIENT_DIR = client_dir
SERVER_DIR = server_dir
LIBFT_DIR = libft
OBJ_DIR = objs

SOURCE_UTILS = $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_putstr_fd.c \
			   $(LIBFT_DIR)/ft_putnbr_fd.c $(LIBFT_DIR)/ft_strlen.c
SOURCE_CLIENT = $(CLIENT_DIR)/client.c 
SOURCE_SERVER = $(SERVER_DIR)/server.c
SOURCE_CLIENT_BONUS = $(CLIENT_DIR)/client_bonus.c
SOURCE_SERVER_BONUS = $(SERVER_DIR)/server_bonus.c

OBJS_UTILS = $(SOURCE_UTILS:%.c=$(OBJ_DIR)/%.o)
OBJS_CLIENT = $(SOURCE_CLIENT:%.c=$(OBJ_DIR)/%.o)
OBJS_SERVER = $(SOURCE_SERVER:%.c=$(OBJ_DIR)/%.o)
OBJS_CLIENT_BONUS = $(SOURCE_CLIENT_BONUS:%.c=$(OBJ_DIR)/%.o)
OBJS_SERVER_BONUS = $(SOURCE_SERVER_BONUS:%.c=$(OBJ_DIR)/%.o)

RM = rm
CC = cc
AR = ar
MAKE_DIR = mkdir

RM_FLAG = -rf
CC_FLAG = -Wall -Wextra -Werror
AR_FLAG = -rcs

all: $(NAME) $(NAME_SERVER)

$(NAME): $(OBJ_DIR) $(OBJS_CLIENT) $(OBJS_UTILS) $(CLIENT_HEADER)
	$(CC) $(CC_FLAG) -o $(NAME) $(OBJS_CLIENT) $(OBJS_UTILS)

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTILS) $(SERVER_HEADER)
	$(CC) $(CC_FLAG) -o $(NAME_SERVER) $(OBJS_SERVER) $(OBJS_UTILS)

clean:
	$(RM) $(RM_FLAG) $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME) $(NAME_SERVER) $(NAME_BONUS) $(NAME_SERVER_BONUS)

bonus: $(NAME_BONUS) $(NAME_SERVER_BONUS)

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_CLIENT_BONUS) $(OBJS_UTILS) $(CLIENT_HEADER)
	$(CC) $(CC_FLAG) -o $(NAME_BONUS) $(OBJS_CLIENT_BONUS) $(OBJS_UTILS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(OBJS_UTILS) $(SERVER_HEADER)
	$(CC) $(CC_FLAG) -o $(NAME_SERVER_BONUS) $(OBJS_SERVER_BONUS) $(OBJS_UTILS)

re: fclean all

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(CLIENT_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(SERVER_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(LIBFT_DIR)

.PHONY: all clean fclean re