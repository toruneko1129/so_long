# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 20:58:53 by hkawakit          #+#    #+#              #
#    Updated: 2021/09/13 17:25:17 by hkawakit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
ifdef WITH_BONUS
SRCDIR	=	./bnssrcs
SRCLIST	=	so_long_bonus.c \
			load_map_bonus.c \
			parse_map_bonus.c \
			data_init_bonus.c \
			load_image_utils_bonus.c \
			draw_bonus.c \
			hook_bonus.c \
			move_bonus.c \
			free_exit_bonus.c \
			error_bonus.c \
			utils_bonus.c
else
SRCDIR	=	./srcs
SRCLIST	=	so_long.c \
			load_map.c \
			parse_map.c \
			data_init.c \
			load_image_utils.c \
			draw.c \
			hook.c \
			move.c \
			free_exit.c \
			error.c \
			utils.c
endif
SRCS	=	$(addprefix $(SRCDIR)/, $(SRCLIST))
OBJDIR	=	./objs
OBJS	=	$(SRCLIST:%.c=$(OBJDIR)/%.o)
LIBDIR	=	./libft
LIBFT	=	ft
MLXDIR	=	./minilibx-linux
MLX		=	mlx_Linux
INCLUDE	=	-I./includes -I$(LIBDIR) -I$(MLXDIR)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-L$(LIBDIR) -l$(LIBFT) -L$(MLXDIR) -l$(MLX) -L/usr/lib/ -lXext \
			-lX11 -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -I/usr/include -O3 -c $< -o $@

$(NAME): $(OBJS)
	make bonus -C $(LIBDIR)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) $^ $(INCLUDE) $(LFLAGS) -o $@ 

all: $(NAME) 

clean:
	make clean -C $(LIBDIR)
	make clean -C $(MLXDIR)
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	make clean -C $(MLXDIR)
	rm -f $(NAME)

re: fclean all

bonus:
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus
