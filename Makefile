# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror

# Directories
SRC_DIR := ./operations
OBJ_DIR := ./obj
LIBFT   := ./.libft

# Files
SRCS    := main.c utils.c \
           $(SRC_DIR)/swap.c
        #    $(SRC_DIR)/rotate.c \
        #    $(SRC_DIR)/rrotate.c \
        #    $(SRC_DIR)/push.c

OBJS    := $(SRCS:%.c=$(OBJ_DIR)/%.o)
NAME    := push_swap

# Colors and emojis
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
RESET   := \033[0m
CHECK   := ✅

# Rules
all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)
	@echo "$(GREEN)Libft compiled successfully! $(CHECK)$(RESET)"

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
	@echo "$(GREEN)Object files cleaned! $(CHECK)$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Executable $(NAME) removed! $(CHECK)$(RESET)"

re: fclean all

.PHONY: all libft clean fclean re
