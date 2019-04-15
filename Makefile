# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 13:27:57 by mwunsch           #+#    #+#              #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_uitoa.c \
	  	ft_strchr_index.c \
	  	ft_strcat_free.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_decimal_converter.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_memset.c \
		ft_printf.c \
		ft_printf_tool_flag_adder.c \
		ft_printf_tool_flag_adder2.c \
		ft_printf_tool_flag_correcter.c \
		ft_printf_tool_lf.c \
		ft_printf_tool_lf2.c \
		ft_printf_tool_c.c \
		ft_printf_tool_di.c \
		ft_printf_tool_di2.c \
		ft_printf_tool_f.c \
		ft_printf_tool_f2.c \
		ft_printf_tool_lc.c \
		ft_printf_tool_ls.c \
		ft_printf_tool_oux.c \
		ft_printf_tool_oux2.c \
		ft_printf_tool_p.c \
		ft_printf_tool_s.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strlowcase.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strupcase.c \
		ft_ustrlen.c \
		ft_ucharlen.c \
		get_next_line.c \
		ft_isalpha.c \
		ft_strrchr.c \
		ft_strstr.c \

OBJS = $(SRC:.c=.o)

INCLUDES = libft.h

all: $(NAME) 

$(NAME): $(OBJS)
	@echo "\x1b[32mLibft: \x1b[0mBuilding library..."
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\x1b[32mLibft: \x1b[0mBuilding library complete"

$(OBJS): %.o: %.c
	@gcc -Wall -Werror -Wextra -c $< -I$(INCLUDES) -o $@

clean:
	@echo "\x1b[32mLibft: \x1b[0mDeleting binaries"
	@rm -f $(OBJS)

fclean: clean
	@echo "\x1b[32mLibft: \x1b[0mDeleting library"
	@rm -f libft.a

re: fclean all

