NAME		:= libftprintf.a

CC			:= gcc
CFLAGS			+= -Wall -Wextra -Werror

SRC_FILES	:= ft_printf.c			\
					pf_eval_fmt.c	\
					pf_conversions.c\
					printf_tools.c	\
					printf_ints.c	\
					ft_imaxtoa.c	\



LFT_FILES :=	ft_memset.c		ft_bzero.c		ft_memcpy.c		\
				ft_memccpy.c	ft_memmove.c	ft_memchr.c		\
				ft_memcmp.c		ft_strlen.c		ft_strdup.c		\
				ft_strcpy.c		ft_strncpy.c	ft_strcat.c		\
				ft_strncat.c	ft_strlcat.c	ft_strchr.c		\
				ft_strrchr.c	ft_strstr.c		ft_strnstr.c	\
				ft_strcmp.c		ft_strncmp.c	ft_atoi.c		\
				ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	\
				ft_isascii.c	ft_isprint.c	ft_toupper.c	\
				ft_tolower.c	ft_memalloc.c	ft_memdel.c		\
				ft_strnew.c		ft_strdel.c		ft_strclr.c		\
				ft_striter.c	ft_striteri.c	ft_strmap.c		\
				ft_strmapi.c	ft_strequ.c		ft_strnequ.c	\
				ft_strsub.c		ft_strjoin.c	ft_strtrim.c	\
				ft_strsplit.c	ft_itoa.c		ft_putchar.c	\
				ft_putstr.c		ft_putendl.c	ft_putnbr.c		\
				ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
				ft_putnbr_fd.c	ft_numsize.c	ft_root.c		\
				ft_itoa_base.c	ft_power.c		ft_count_words.c\
				ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		\
				ft_lstadd.c		ft_lstiter.c	ft_lstmap.c		\
				ft_fmod.c		ft_realloc.c

LIBFTHEADER		:= ./libft/libft.h
SRCHEADER		:= ./src/ft_printf.h

SRC				:= $(addprefix src/, $(SRC_FILES))
LIBFTSRC		:= $(addprefix libft/, $(LFT_FILES))

OBJ				:= $(SRC:.c=.o)
OBJLIBFT 		:= $(LIBFTSRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(CFLAGS) -I $(SRCHEADER) -c $< -o $@

$(OBJLIBFT): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFTHEADER) -c $< -o $@

$(NAME): $(OBJLIBFT) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(OBJLIBFT)
	@echo "libftprintf.a compiled"

clean:
	@rm -rf $(OBJ) $(OBJLIBFT) $(OBJTEST)
	@rm -rf main.o
	@echo "all .o files removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "libftprintf.a removed"

re: fclean all

main: $(NAME)
	@$(CC) main.c $(NAME) -o main
	./main
	@rm main

debug:
	@$(CC) -g $(CFLAGS) $(SRC) $(LIBFTSRC) main.c $(NAME) -o debug
	lldb
