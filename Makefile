# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 10:46:10 by csphilli          #+#    #+#              #
#    Updated: 2020/06/18 14:25:35 by cphillip         ###   ########.fr        #
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
SRC_FILES = create.c\
			scanning.c\
			find_median.c\
			unshifts.c\
			sorting_parser.c\
			ra_rb_rr.c\
			sa_sb_ss.c\
			rra_rrb_rrr.c\
			pa_pb.c\
			check_orders.c\
			sort_2_and_3_numbers.c\
			sort_5_and_6_numbers.c\
			sort_a_to_b.c\
			sort_b_to_a.c\
			sort_large_sets.c\
			get_next.c\
			get_directions.c\
			pops.c\
			arg_parsing.c\
			free_list_a.c\
			next_nbr.c\
			ok_ko.c\
			help.c\
			error.c

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
