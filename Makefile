NAME	=	libftprintf.a

SRC_DIR	=	srcs/

SRC_FILES=	ft_printf.c \
					print_char.c \
					utils_str_mng.c \
					flags_management.c \
					print_string.c \
					specifier_management.c \
					utils_basic.c \
					flags_management_utils.c \
					itoa_base.c	\
					print_int.c	\
					print_unsigned.c \
					print_hexa.c \
					print_pointer.c \
					utils.c


OBJS	=		${addprefix ${SRC_DIR},${SRC_FILES:.c=.o}}

CC		=	gcc

RM		=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

HEADER=		include

.c.o:
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

${NAME}:	${OBJS}
				ar -vrc ${NAME} ${OBJS}

all:		${NAME}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:				fclean all

.PHONY:		all clean fclean re

