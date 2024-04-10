NAME = client
NAME_SERVER = server

CLIENT_HEADER = $(CLIENT_DIR)/client.h
SERVER_HEADER = $(SERVER_DIR)/server.h

CLIENT_DIR = client_dir
SERVER_DIR = server_dir
LIBFT_DIR = libft
OBJ_DIR = objs

SOURCE_UTILS = libft/ft_atoi.c libft/ft_putstr_fd.c
SOURCE_CLIENT = client_dir/client.c 
SOURCE_SERVER = server_dir/server.c

OBJS_UTILS = $(SOURCE_UTILS:%.c=$(OBJ_DIR)/%.o)
OBJS_CLIENT = $(SOURCE_CLIENT:%.c=$(OBJ_DIR)/%.o)
OBJS_SERVER = $(SOURCE_SERVER:%.c=$(OBJ_DIR)/%.o)

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
	$(RM) $(RM_FLAG) $(OBJ_DIR)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME) $(NAME_SERVER)

re: fclean all

re_exe_mand: fclean exe

exe_client:
	$(CC) $(CC_FLAG) -o $(NAME) $(SOURCE_CLIENT) $(SOURCE_UTILS)
	@./$(NAME)

exe_server:
	$(CC) $(CC_FLAG) -o $(NAME_SERVER) $(SOURCE_SERVER) $(SOURCE_UTILS)
	@./$(NAME_SERVER)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(CLIENT_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(SERVER_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(LIBFT_DIR)

.PHONY: all clean fclean re