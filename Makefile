# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 14:19:08 by mzhivoto          #+#    #+#              #
#    Updated: 2025/03/23 12:22:06 by mzhivoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = so_long
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/

SRCS_PATH = ./src
OBJS_PATH = ./obj
LIBFT_PATH = ./libft

# Source files and object files
LIBFT = $(LIBFT_PATH)/libft.a
SRC = $(SRCS_PATH)/main.c \
	$(SRCS_PATH)/parse_args.c \
	$(SRCS_PATH)/error_msg.c \
	$(SRCS_PATH)/map_check.c \
	$(SRCS_PATH)/floodfill.c \

	

OBJ := $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRC))

# Default rule to create the library
all: $(NAME)

# Rule to create the library from object files
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

# Compile each .c file into a .o file
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# Clean rule to remove object files and the library
clean:
	@rm -rf $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
