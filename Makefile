# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nathan <nathan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 17:14:38 by nathan            #+#    #+#              #
#    Updated: 2019/10/02 13:44:06 by aben-azz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_retro


FILES= main Cursor

SRC_DIR= src/
SRC= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))
OBJ_DIR = obj/
OBJ= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

C++FLAGS= -Wall -Wextra -Werror -std=c++98 -c

CC=c++




all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $< -lncurses

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(C++FLAGS) $< -o $@ -I./src/includes

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re ft_retro
