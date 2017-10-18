NAME				= fractol

COMPILER			= gcc

CC_FLAGS			= -Wall -Werror -Wextra -g

LIBFT				= libft/libft.a

LIB_FLAG = -lmlx -framework OpenGL -framework AppKit -Llibft -lft

LIBNUX_FLAG = -L/usr/X11/lib -lXext -lX11 mlx/libmlx.a

INC					= includes/

SRC_DIR				= srcs

SRC		=	main.c \
        ft_launcher.c \
		ft_fractol.c \
		ft_julia.c \
        ft_mandelbrot.c \
        ft_mandelbrot5.c \
        ft_mandelbrot4.c \
        ft_burning_ship.c \
        ft_burning_ship2.c \
        ft_tricorne.c \
		ft_celtic_heart.c

SRCS				= $(addprefix $(ASM_SRC_DIR)/, $(ASM_SRC))

OBJ					= $(SRC:.c=.o)


OBJS_DIR			= .objs

OBJS				= $(addprefix $(OBJS_DIR)/, $(OBJ))

all : proj $(LIBFT) $(NAME)

proj:
ifneq ($(shell test -e corewar && test -e asm;echo $$?), 0)
	@echo ""
	@echo "______ ______   ___   _____  _____  _____  _     "
	@echo "|  ___|| ___ \ / _ \ /  __ \|_   _||  _  || |    "
	@echo "| |_   | |_/ // /_\ \| /  \/  | |  | | | || |    "
	@echo "|  _|  |    / |  _  || |      | |  | | | || |    "
	@echo "| |    | |\ \ | | | || \__/\  | |  \ \_/ /| |____"
	@echo "\_|    \_| \_|\_| |_/ \____/  \_/   \___/ \_____/"
	@echo ""
endif

.objs/%.o:srcs/%.c $(INC)
	@mkdir -p .objs
	@$(COMPILER) $(CC_FLAGS) -I $(INC) -c $< -o $@ || (echo "\033[K \033[36mFRACTOL :      \033[0m [\033[31m $(notdir $<)\033[0m ] \033[31m✕\033[0m")
	@echo "\033[K \033[36mFRACTOL :      \033[0m [ compiling :\033[33m $(notdir $<)\033[0m ]\033[1A"

$(NAME): $(OBJS) $(INC) $(LIBFT)
	@$(COMPILER) $(CC_FLAGS) $(LIB_FLAG) $(OBJS) -L libft/ -lft -o $(NAME) || (echo "\033[1A\033[K \033[36mCompilation\033[0m" "[\033[31m  " $(NAME) "\033[0m  ]" "\033[31m✕\033[0m"; exit 1)
	@echo " \033[36mCompilation\033[0m" "[\033[32;1m  " $(NAME) "\033[0m  ]" "\033[K\033[0;32;1m✓\033[0m"
 
ifneq ($(shell make -q -C libft/;echo $$?), 0)
.PHONY: $(LIBFT)
$(VISU)
endif

$(LIBFT):
	@Make -C libft/

clean:
	@echo " \033[36mDeletion    \033[0m[\033[33m objects  \033[0m]"  "\033[K\033[0;32;1m✓\033[0m"
	@rm -rf $(OBJS)
	@Make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@echo " \033[36mDeletion    \033[0m[\033[33m binaries \033[0m]"  "\033[K\033[0;32;1m✓\033[0m"
	@rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: fclean
	@make all	

.PHONY: all clean fclean re
