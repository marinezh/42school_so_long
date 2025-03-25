# **************************************************************************** #
#                                CONFIGURATION                                 #
# **************************************************************************** #

NAME        = so_long
CC          = cc

# Paths
SRCS_PATH   = ./src
OBJS_PATH   = ./obj
LIBFT_PATH  = ./libft
LIBFT       = $(LIBFT_PATH)/libft.a
MLX42_PATH  = ./MLX42
MLX42_BUILD = $(MLX42_PATH)/build
MLX42_LIB   = $(MLX42_BUILD)/libMLX42.a
MLX42_REPO  = https://github.com/codam-coding-college/MLX42.git

# Homebrew GLFW paths
GLFW_PATH   = $(shell brew --prefix glfw)

# Flags
CFLAGS      = -Wall -Wextra -Werror -I./includes -I$(MLX42_PATH)/include -I$(GLFW_PATH)/include
LDFLAGS     = -L$(MLX42_BUILD) -lMLX42 $(GLFW_PATH)/lib/libglfw3.a \
              -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Sources
SRC         = $(SRCS_PATH)/main.c \
              $(SRCS_PATH)/parse_args.c \
              $(SRCS_PATH)/error_msg.c \
              $(SRCS_PATH)/map_check.c \
              $(SRCS_PATH)/floodfill.c \
              $(SRCS_PATH)/mlx_test.c \
              $(SRCS_PATH)/game_init.c \
              $(SRCS_PATH)/game_events.c

OBJ         = $(patsubst $(SRCS_PATH)/%.c, $(OBJS_PATH)/%.o, $(SRC))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX42_LIB):
	@if [ ! -d $(MLX42_PATH) ]; then git clone $(MLX42_REPO) $(MLX42_PATH); fi
	cmake -S $(MLX42_PATH) -B $(MLX42_BUILD)
	cmake --build $(MLX42_BUILD)

clean:
	@rm -rf $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -rf $(MLX42_BUILD)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
