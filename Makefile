##
## Makefile for Makefile in /home/mathon_j/rendu/PSU_2014_philo
## 
## Made by Jérémy MATHON
## Login   <mathon_j@epitech.net>
## 
## Started on  Fri Feb 20 09:35:47 2015 Jérémy MATHON
## Last update Fri Feb 20 14:48:33 2015 Jérémy MATHON
##

CC	=	cc

NAME	=	philo

SRC	=	source/main.c		\
		source/init_res.c	\
		source/philosophes.c	\


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -lpthread -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
