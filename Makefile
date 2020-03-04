# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qlouisia <qlouisia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 16:56:04 by lgrudler          #+#    #+#              #
#    Updated: 2020/03/04 19:40:57 by qlouisia         ###   ########.fr        #
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
CFLAGS= -g3 `sdl2-config --cflags` #-Wall -Wextra -Werror
SRC_DIR= src/
SRC= main.c\
	ft_parser.c\
	exit.c\
	draw.c\
	raycast.c\
	key_event.c\
	fps.c\
	init.c\
	color.c\
	bmp_parser.c\
	huit_bits.c\
	exit_bmp.c\
	menu.c\
	hud.c\
	check_map.c\
	clear.c

SRCS= $(addprefix $(SRC_DIR),$(SRC))
ABS_DIR= $(shell pwd)
OBJ_DIR= obj/

LFT_DIR= libft
LFT= $(LFT_DIR)/libft.a

OBJ= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

LIB= -L libft -lft `sdl2-config --libs` `sdl2-config --libs`_ttf

###############################################################################
#								Rules										  #
###############################################################################

all: $(NAME)

$(NAME): $(LFT) $(SDL2) $(SDL_TTF) $(OBJ)
	@ echo "$(YELLOW)Creating $@ executable$(WHITE)"
	@ $(CC) -o $@ $(CFLAGS) $(OBJ) $(LIB)
	@ echo "$(GREEN)$@ executable created$(WHITE)"

$(LFT):
	@ echo "$(BLUE)Creating libft$(WHITE)"
	@ make -sC $(LFT_DIR) -j
	@ echo "$(GREEN)Libft created$(WHITE)"

$(SDL2):
	@ echo "$(YELLOW)Installing library SDL2$(WHITE)";
	@ brew install sdl2
	@ echo "$(GREEN)SDL2 created$(WHITE)"

$(SDL_TTF):
	@ echo "$(YELLOW)Installing library SDL2_TTF$(WHITE)";
	@ brew install sdl2_ttf
	@ echo "$(GREEN)SDL2_TTF created$(WHITE)"


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

re: fclean all

.PHONY: all clean fclean re
