# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/30 10:46:10 by csphilli          #+#    #+#              #
#    Updated: 2020/04/01 15:10:11 by csphilli         ###   ########.fr        #
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
			check_for_duplicates.c\
			error.c\
			push_pop_unshift.c\
			steps_master.c\
			first_step.c\
			second_step.c\
			third_step.c\
			fourth_step.c\
			fifth_step.c\
			ra_rb_rr.c\
			sa_sb_ss.c\
			rra_rrb_rrr.c\
			pa_pb.c\
			run_program.c\
			main.c\
			check_order.c

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
