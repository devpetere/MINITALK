RM = rm -rf
FLAGS = -Wall -Wextra -Werror -g
FT_PRINTF = FT_PRINTF/libftprintf.a

SOURC_UTILS = ft_atoi.c \
			  ft_strlen.c \
			  ft_strjoin.c \
			  ft_itoa.c \
			  ft_calloc.c \
			  ft_bzero.c

SOURC_CLIENT = ./client.c

SOURC_SERVEUR = ./serveur.c

OBJS_UTILS = $(SOURC_UTILS:.c=.o)

OBJS_CLIENT = $(SOURC_CLIENT:.c=.o)

OBJS_SERVEUR = $(SOURC_SERVEUR:.c=.o) 

%.o : %.c
	cc $(FLAGS) -c $< 
	
all : client serveur

$(FT_PRINTF) :
	make -C ./FT_PRINTF/

client : $(OBJS_CLIENT) $(FT_PRINTF) 
	cc $(FLAGS) $(SOURC_CLIENT) $(SOURC_UTILS) $(FT_PRINTF) -o client
	
serveur : $(OBJS_SERVEUR) $(FT_PRINTF)
	cc $(FLAGS) $(SOURC_SERVEUR) $(SOURC_UTILS) $(FT_PRINTF) -o serveur

clean : 
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVEUR) 
	$(RM) $(OBJS_UTILS)
	make clean -C ./FT_PRINTF 

fclean : clean
	$(RM) client serveur
	make fclean -C ./FT_PRINTF

re : fclean all

.PHONY : re fclean clean 

