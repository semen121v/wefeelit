# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fshade <fshade@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 15:33:21 by ldonnis           #+#    #+#              #
#    Updated: 2019/02/18 18:47:09 by fshade           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
FLAG = -Wall -Wextra -Werror -g -ggdb
SRC = main.c fillit.c valid_tetriminos.c newlist.c map.c coordinates.c readfile.c newtetrimo.c size.c
OBJ = $(SRC:.c=.o)
LIB = libft.a


all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	clang -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft -g

$(LIB):
	$(MAKE) -C libft/ fclean && make -C libft/ 

%.o: %.c $(HEADER)
	clang -Wall -Wextra -Werror -I libft/includes -o $@ -c $< -g 
	
clean:
	@rm -f $(OBJ)
	$(MAKE) -C libft/ clean 

fclean: clean 
	@rm -f $(NAME)
	$(MAKE) -C libft/ fclean 

re: fclean all