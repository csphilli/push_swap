# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 10:46:10 by csphilli          #+#    #+#              #
#    Updated: 2020/04/07 20:53:08 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap

HEADER_FILES = push_swap.h

CC = gcc -Wall -Wextra -Werror
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER)

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)header/
LIBRARIES = -lft -L$(LIBFT_DIR)

HEADER_DIR = ./includes/
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRC_DIR = ./src/
SRC_FILES = display_list.c\
			create.c\
			scanning.c\
			error.c\
			push_pop_unshift.c\
			begin_sort.c\
			ra_rb_rr.c\
			sa_sb_ss.c\
			rra_rrb_rrr.c\
			pa_pb.c\
			run_program.c\
			main.c\
			check_orders.c\
			sort_short.c\
			sort_a_to_b.c\
			sort_b_to_a.c\
			bsort.c\
			charm.c\
			the_big_sort.c\
			find_cheapest.c\
			get_directions.c\

all: $(NAME_PS)

$(NAME_PS): $(OBJ_DIR) $(LIBFT) $(OBJECTS)
	$(CC) $(INCLUDES) $(OBJECTS) -o $(NAME_PS) $(LIBRARIES)

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

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
