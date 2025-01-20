.SILENT:

# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror

# Directories
SRC_DIR := ./operations
OBJ_DIR := ./obj
LIBFT   := ./.libft

# Files
SRCS    := main.c utils.c radix.c sorting.c ft_atoi_overflow.c iwanttobreakfree.c \
           $(SRC_DIR)/swap.c \
           $(SRC_DIR)/push.c \
           $(SRC_DIR)/rotate.c \
           $(SRC_DIR)/rrotate.c

OBJS    := $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME    := push_swap

# Colors and emojis
GREEN   := \033[0;32m
YELLOW := \033[38;5;226m
ORANGE  := \033[38;5;208m
RESET   := \033[0m
CHECK   := ✅

# Rules
all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)
	@echo "$(YELLOW)Libft compiled successfully! $(CHECK)$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created! $(CHECK)$(RESET)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling: $<\\r$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiled: $< $(CHECK)\\n$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(ORANGE)Object files cleaned! $(CHECK)$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(ORANGE)Executable $(NAME) removed! $(CHECK)$(RESET)"

re: fclean all

.PHONY: all libft clean fclean re
