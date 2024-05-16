##
## EPITECH PROJECT, 2023
## my_hunter
## File description:
## mkfl myhunter
##

SRC	=	main.c	\
		lib.c	\
		hunt.c	\
		realmain.c	\
		display.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

RM	=	rm -rf

FLAGS	= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all
