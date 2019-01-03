# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 15:10:07 by dkhatri           #+#    #+#              #
#    Updated: 2018/12/20 18:22:41 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

MAIN = main.c

FLAGS = 

SRCDIR = ./src/

HELPER = ft_sqrt.c get_next_line.c

PARSOR = ft_pointop.c ft_fillop.c ft_parse_file.c ft_parse_tetri.c ft_compute.c

SRCO = $(addprefix $(SRCDIR), $(PARSOR:.c=.o)) \
		$(addprefix $(SRCDIR), $(GNL:.c=.o)) \
		$(addprefix $(SRCDIR), $(HELPER:.c=.o)) \
		$(MAIN:.c=.o)

DEPS = ./includes/fillit.h ./libft/libft.h

%.o: %.c $(DEPS)
	gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft
	gcc -o $(NAME) $(SRCO) -L libft/ -lft

clean :
	make -C libft clean
	/bin/rm -f $(SRCO)

fclean : clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re : fclean all
