# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 10:46:10 by csphilli          #+#    #+#              #
#    Updated: 2020/04/10 02:41:01 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

HEADER_FILES = push_swap.h

CC = gcc -Wall -Wextra -Werror
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER)

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)header/
LIBRARIES = -lft -L$(LIBFT_DIR)

HEADER_DIR = ./includes/
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_FILES))

SRC_DIR = ./src/
SRC_FILES = display_list.c\
			create.c\
			scanning.c\
			find_median.c\
			error.c\
			unshifts.c\
			begin_sort.c\
			ra_rb_rr.c\
			sa_sb_ss.c\
			rra_rrb_rrr.c\
			pa_pb.c\
			run_program.c\
			check_orders.c\
			sort_short.c\
			sort_a_to_b.c\
			sort_b_to_a.c\
			the_big_sort.c\
			find_cheapest.c\
			get_directions.c\
			pushes.c\
			pops.c\
			parsing.c

SRC_FILES_PS = push_swap.c
SRC_FILES_CH = checker.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRCS_PS = $(addprefix $(SRC_DIR), $(SRC_FILES_PS))
SRCS_CH = $(addprefix $(SRC_DIR), $(SRC_FILES_CH))

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ_FILES_PS = $(SRC_FILES_PS:%.c=%.o)
OBJ_FILES_CH = $(SRC_FILES_CH:%.c=%.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
OBJECTS_PS = $(addprefix $(OBJ_DIR), $(OBJ_FILES_PS))
OBJECTS_CH = $(addprefix $(OBJ_DIR), $(OBJ_FILES_CH))

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJ_DIR) $(LIBFT) $(OBJECTS) $(OBJECTS_PS)
	$(CC) $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) -o $(NAME_PS) $(LIBRARIES)

$(NAME_CH): $(OBJ_DIR) $(LIBFT) $(OBJECTS) $(OBJECTS_CH)
	$(CC) $(INCLUDES) $(OBJECTS) $(OBJECTS_CH) -o $(NAME_CH) $(LIBRARIES)

$(OBJ_DIR):
	@mkdir -p obj
	@echo "Object directory created"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADERS)
	@-$(CC) -c $(INCLUDES) $< -o $@
	@echo "$@ file created"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "Libft.a created"

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIBFT)
	@rm -rf $(NAME_PS)
	@rm -rf $(NAME_CH)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
