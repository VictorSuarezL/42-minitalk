NAME = pipex
OBJ_DIR = obj

# Libft
LIBFT = libft.a
LIBFT_SRC = ./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra

# Colours
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
WHITE				=	\033[0;37m
RESET				=	\033[0m

SRC_FILES = src/main.c \

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

# Rules
all: $(LIBFT) $(NAME)
	@printf "$(BLUE)==> $(CYAN)Compiled\n$(RESET)"

$(LIBFT):
	@make -C libft bonus

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
	@$(RM) $(NAME) $(OBJS)
	@printf "$(BLUE)==> $(RED)Removed\n$(RESET)"

fclean: clean
	@make -C libft fclean

re: fclean all
	@printf "$(BLUE)==> $(CYAN)Recompiled\n$(RESET)"

.PHONY: all clean fclean re