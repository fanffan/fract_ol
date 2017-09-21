#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaury <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2017/03/10 17:55:12 by fmaury           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= fractol

COMPILER		= gcc

CC_FLAGS		= -Wall -Werror -Wextra -g

LIB_FLAG = -framework OpenGL -framework AppKit utilitaire/minilibx_macos/libmlx.a

LIBNUX_FLAG = -L/usr/X11/lib -lXext -lX11 mlx/libmlx.a

INC				= ./includes

SRC_DIR		= ./srcs

SRC		=	main.c \
        ft_launcher.c \
        ft_mandelbrot.c

OBJ		= $(SRC:.c=.o)


NEWLINE		= @echo ""

all : $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(NEWLINE)
	@echo "Compilation..."
	@$(NEWLINE)
	#$(MAKE) -C Libft/
	$(COMPILER) $(CC_FLAGS) $(OBJ) $(LIBNUX_FLAG) Libft/libft.a -o $(NAME) 
	@echo "Fract'ol cree !"
	$(NEWLINE)

%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CC_FLAGS) -I $(INC) -c $< -o $@

clean:
	@echo "Suppression des objets"
	$(NEWLINE)
	@rm -f $(FDF_OBJ)

fclean: clean
	@echo "Suppression de l'executable"
	$(NEWLINE)
	@rm -f $(NAME)

re: fclean 
	@$(MAKE) all

.PHONY: all clean fclean re
