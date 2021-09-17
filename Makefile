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
SRCDIR	=	./srcs
SRCLIST	=	so_long.c \
			load_map.c \
			parse_map.c \
			data_init.c \
			draw.c \
			hook.c \
			free_exit.c \
			error.c \
			utils.c
SRCS	=	$(addprefix $(SRCDIR)/, $(SRCLIST))
OBJDIR	=	./objs
OBJS	=	$(SRCLIST:%.c=$(OBJDIR)/%.o)
LIBDIR	=	./libft
LIBFT	=	ft
MLXDIR	=	./minilibx-linux
MLX	=	mlx_Linux
INCLUDE	=	-I./includes -I$(LIBDIR) -I$(MLXDIR)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-L$(LIBDIR) -l$(LIBFT) -L$(MLXDIR) -l$(MLX) -L/usr/lib -lXext \
		-lX11 -lm -lz

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

.PHONY: all clean fclean re
