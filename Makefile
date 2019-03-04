# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 19:36:57 by juepee-m          #+#    #+#              #
#    Updated: 2019/02/27 19:57:18 by juepee-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ_DIR = ./obj/
LIB_PATH = ./libft/

HEADER = \
			fillit.h

SRC_NAME =	\
			main.c\
			main_solve.c\
			do_list.c\
			valid_shape.c\
			power.c\
			mapper.c\
			ft_display.c\
			free.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
CPPFLAGES = -I$(HEADER)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

DEPS = $(OBJS:.o=.d)

LIBFT = $(LIB_PATH)libft.a
LIBLINK = -L $(LIB_PATH) -lft

# COLORS
WHITE =`echo "\033[0m"`
CYAN =`echo "\033[36m"`
BLUE = `echo "\033[34m"`
GREEN =`echo "\033[32m"`
YELLOW =`echo "\033[33m"`
BOLDRED = `echo "\033[1m\033[31m"`
PROJECT = "FILLIT"

.PHONY : all clean fclean re norm

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBLINK)
	@echo "$(CYAN)$(PROJECT) | Compiling $(BOLDRED) [ $(NAME) ] $(GREEN) SUCCESS $(WHITE)"

$(LIBFT) : $(LIB_PATH)
	@make -C $(LIB_PATH)

-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o : %.c Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD $(CPPFLAGS) -c $< -o $@
	@echo "$(CYAN)$(PROJECT) | Linking $(BLUE) [ $< ] $(GREEN) OK $(WHITE)"

clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)
	@echo "$(CYAN)$(PROJECT) | clean $(YELLOW):trèfle:  object files cleaned$(WHITE)"

fclean :
	@make fclean -C $(LIB_PATH)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@echo "$(CYAN)$(PROJECT) | clean $(YELLOW):trèfle:  object files cleaned$(WHITE)"
	@echo "$(CYAN)$(PROJECT) | fclean $(YELLOW):trèfle:  executable $(BOLDRED)($(NAME)) $(YELLOW)cleaned$(WHITE)"

re : fclean all
	@echo "$(CYAN)$(PROJECT) | re $(YELLOW):recyclage:  $(BOLDRED)[ $(NAME) ] $(YELLOW)REBUILT$(WHITE)"

norm :
	@norminette -R CheckForbiddenSourceHeader $(HEADER) $(SRC_NAME)
