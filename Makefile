# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grudler <grudler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 16:56:04 by lgrudler          #+#    #+#              #
#    Updated: 2020/02/27 16:06:17 by grudler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m
YELLOW= \033[33m
MAGENTA= \033[35m

################################################################################
#								Macros										   #
################################################################################
NAME= wolf3d
CC= gcc
CFLAGS= -g3 -fsanitize=address #-Wall -Wextra -Werror #
SRC_DIR= src/
SRC= main.c\
	ft_parser.c\
	exit.c\
	draw.c\
	raycast.c\
	key_event.c\
	fps.c\
	display.c\
	init.c\
	color.c\
	bmp_parser.c\
	8bits.c\
	exitBMP.c\
	menu.c

SRCS= $(addprefix $(SRC_DIR),$(SRC))
ABS_DIR= $(shell pwd)
OBJ_DIR= obj/
SDL_DIR= $(ABS_DIR)/lib/SDL2-2.0.10/
OBJ= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
LIB= -L libft -lft `sdl2-config --cflags --libs`

###############################################################################
#								Rules										  #
###############################################################################

all: $(NAME)

$(NAME): sdl2 $(OBJ)
	@ echo "$(BLUE)Creating libft$(WHITE)"
	@ make -C libft
	@ echo "$(GREEN)Libft created$(WHITE)"
	@ echo "$(YELLOW)Creating $@ executable$(WHITE)"
	@ $(CC) -o $@ $(CFLAGS) $(OBJ) $(LIB)
	@ echo "$(GREEN)$@ executable created$(WHITE)"

sdl2:
	@mkdir -p SDL2/build
	@cd SDL2/build; 									\
	$(SDL_DIR)/configure --prefix $(ABSDIR)/SDL2;		\
	make; 												\

obj:
	@mkdir obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c |obj
	@ $(CC) -o $@ -c $< $(CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
	@ echo "$(BLUE)Cleaning libft$(WHITE)"
	@ make -C libft clean
	@ echo "$(YELLOW)Deleting objects$(WHITE)"
	@ for i in $(OBJ); do \
		echo "$(RED)-Deleting $$i$(WHITE)"; \
	done;
	@ echo "$(GREEN)Objects deleted$(WHITE)"
	@ rm -rf $(OBJ)

fclean: clean
	@ echo "$(BLUE)Cleaning libft$(WHITE)"
	@ make -C libft fclean
	@ echo "$(YELLOW)Deleting obj directory$(WHITE)"
	@ rm -rf obj
	@ echo "$(GREEN)Obj directory deleted$(WHITE)"
	@ rm -rf $(NAME)
	@ echo "$(GREEN)Executable deleted$(WHITE)"

clear: fclean
	@ rm -rf sdl2
	@ echo "$(GREEN)Sdl2 deleted$(WHITE)"

re: fclean all

.PHONY: all clean fclean re clear
