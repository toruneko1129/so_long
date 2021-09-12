# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkawakit <hkawakit@student.42tokyo.j>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 20:58:53 by hkawakit          #+#    #+#              #
#    Updated: 2021/09/12 21:58:02 by hkawakit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRCDIR	=	./srcs
SRCLIST	=	so_long.c \
			error.c
SRCS	=	$(addprefix $(SRCDIR)/, $(SRCLIST))
OBJDIR	=	./objs
OBJS	=	$(SRCLIST:%.c=$(OBJDIR)/%.o)
INCLUDE	=	-I./includes
LIBDIR	=	./libft
LIBFT	=	ft
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-L$(LIBDIR) -l$(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	make bonus -C $(LIBDIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(LFLAGS) $^ -o $@ 

all: $(NAME) 

clean:
	make clean -C $(LIBDIR)
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
