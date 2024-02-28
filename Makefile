NAME = minitalk
OBJ_DIR = obj
SRC_DIR = src

# Libft
LIBFT = libft.a
LIBFT_SRC = ./lib/libft/

# Compiler
CC					=	gcc
RM					=	rm -f
HEADERS 			= 	-I ./includes -I $(LIBFT_SRC)
# CFLAGS				=	-Wall -Werror -Wextra -I$(HEADERS)
CFLAGS				=	$(HEADERS)
# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

SRC_FILES_SERVER = $(SRC_DIR)/server.c 
SRC_FILES_CLIENT = $(SRC_DIR)/client.c 

OBJ_SERVER = $(SRC_FILES_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_FILES_CLIENT:.c=.o)

# Rules
all: $(NAME)
	@printf "$(BLUE)==> $(CYAN)Compiled\n$(RESET)"

$(NAME): server client

$(LIBFT):
	make -C $(LIBFT_SRC) 

server: $(LIBFT) $(OBJ_SERVER)
	gcc -o $@ $(OBJ_SERVER) $(CFLAGS) $(LIBFT_SRC)$(LIBFT)

client: $(LIBFT) $(OBJ_CLIENT)
	gcc -o $@ $(OBJ_CLIENT) $(CFLAGS) $(LIBFT_SRC)$(LIBFT)

$(OBJ_SERVER): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	$(info    OBJ_SERVER is $(OBJ_SERVER))
	$(info    OBJ_CLIENT is $(OBJ_CLIENT))

# $(OBJ_SERVER): %.o: %.c
# 	$(CC) $(CFLAGS) -o $@ -c $<
# 	$(info    OBJ_SERVER is $(OBJ_SERVER))

clean:
	$(RM) $(NAME) $(OBJ_SERVER) $(OBJ_CLIENT)
	make -C $(LIBFT_SRC) clean
	@printf "$(BLUE)==> $(RED)Removed\n$(RESET)"

fclean: clean
	rm -rf server client
	@make -C $(LIBFT_SRC) fclean

re: fclean all
	@printf "$(BLUE)==> $(CYAN)Recompiled\n$(RESET)"

.PHONY: all clean fclean re