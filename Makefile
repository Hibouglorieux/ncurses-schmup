# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nathan <nathan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 17:14:38 by nathan            #+#    #+#              #
#    Updated: 2019/10/02 16:52:25 by aben-azz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\x1b[0m
_BOLD		=	\x1b[1m
_UNDER		=	\x1b[4m
_REV		=	\x1b[7m
_GREY		=	\x1b[30m
_RED		=	\x1b[31m
_GREEN		=	\x1b[32m
_YELLOW		=	\x1b[33m
_BLUE		=	\x1b[34m
_PURPLE		=	\x1b[35m
_CYAN		=	\x1b[36m
_WHITE		=	\x1b[37m
_IGREY		=	\x1b[40m
_IRED		=	\x1b[41m
_IGREEN		=	\x1b[42m
_IYELLOW	=	\x1b[43m
_IBLUE		=	\x1b[44m
_IPURPLE	=	\x1b[45m
_ICYAN		=	\x1b[46m
_IWHITE		=	\x1b[47m
_MAGENTA	=	\x1b[35m

NAME     := ft_retro
OBJPATH  := .obj/
SRC_DIR  := ./src/
MSG			=	$(_BOLD)$(_BLUE)Compiling ft_retro$(_END)
LONGEST		:=	$(shell echo $(notdir $(SRC)) | tr " " "\n" | awk ' { if (\
			length > x ) { x = length; y = $$0 } }END{ print y }' | wc -c)
SRCS     := main.cpp Cursor.cpp
SRC      :=$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRCS)))
OBJS     := $(SRCS:.cpp=.o)
OBJ      := $(addprefix $(OBJPATH), $(OBJS))

CPP      := g++
FLAGS    := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(OBJ) -o $@ -lncurses
	@printf "\r\033[K$(_BOLD)$(_RED)./$(NAME) is ready for use\n$(_END)"

$(OBJPATH)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJPATH)
	@printf "\r\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)" $(notdir $<)

	@$(CPP) $(FLAGS) -o $@ -c $< -I./src/includes

clean:
	@rm -rf $(OBJ) $(OBJPATH)
	@echo "$(_RED)[INFO] Objects removed!$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_RED)[INFO] $(NAME) removed!$(_END)"

re:     fclean all

.PHONY: all clean fclean ft_retro re
