# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhivoto <mzhivoto@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 14:19:08 by mzhivoto          #+#    #+#              #
#    Updated: 2025/03/26 13:18:28 by mzhivoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = so_long
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./MLX42/include -Wunreachable-code -Ofast
LDFLAGS = -ldl -lglfw -pthread -lm

SRCS_PATH = ./src
OBJS_PATH = ./obj
LIBFT_PATH = ./libft
MLX_PATH = ./MLX42
MLX_REPO = https://github.com/codam-coding-college/MLX42.git

# Source files and object files
MLXLIB = MLX42/build/libmlx42.a
LIBFT = $(LIBFT_PATH)/libft.a
SRC = $(SRCS_PATH)/main.c \
	$(SRCS_PATH)/parse_args.c \
	$(SRCS_PATH)/utils.c \
	$(SRCS_PATH)/map_check.c \
	$(SRCS_PATH)/floodfill.c \
	$(SRCS_PATH)/game_init.c \
	$(SRCS_PATH)/game_events.c \
	$(SRCS_PATH)/game_render.c \

OBJ := $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRC))

# Default rule to create the library
all: $(MLX_PATH) $(NAME)

# Rule to create the library from object files
$(NAME): $(OBJ) $(LIBFT) $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXLIB) $(LDFLAGS) -o $(NAME)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

# Compile each .c file into a .o file
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

#Clone and build MLX42
$(MLX_PATH):
	git clone $(MLX_REPO) $(MLX_PATH)
	cmake -B $(MLX_PATH)/build -S $(MLX_PATH) -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_EXAMPLES=OFF
	cmake --build $(MLX_PATH)/build

mlx_update:
	@if [ -d "$(MLX_PATH)" ]; then \
		echo "Updating MLX42..."; \
		cd $(MLX_PATH) && git pull && \
		cmake -B build -S . -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_EXAMPLES=OFF && \
		cmake --build build; \
	else \
		echo "MLX42 not found. Run 'make' to clone and build."; \
	fi

# Build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# Clean rule to remove object files and the library
clean:
	@rm -rf $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(MLX_PATH)/build

fclean: clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re