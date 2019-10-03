# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nathan <nathan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 17:14:38 by nathan            #+#    #+#              #
#    Updated: 2019/10/03 18:52:37 by aben-azz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := ft_retro
OBJPATH  := .obj/
SRC_DIR  := src/
MSG			=	Compiling ft_retro
SRCS     := main.cpp Cursor.cpp ADisplay.cpp Ennemy1.cpp Manager.cpp Player.cpp
SRC      :=$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRCS)))
OBJS     := $(SRCS:.cpp=.o)
OBJ      := $(addprefix $(OBJPATH), $(OBJS))

CPP      := g++
FLAGS    := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(OBJ) -o $@ -lncurses
	@printf "\r $(NAME) is ready for use\n"

$(OBJPATH)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJPATH)
	@printf "\r $(MSG)" $(notdir $<)

	@$(CPP) $(FLAGS) -o $@ -c $< -I./src/includes

clean:
	@rm -rf $(OBJPATH)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re:     fclean all

.PHONY: all clean fclean ft_retro re
