RM = rm -rf
FLAGS = -Wall -Wextra -Werror -g
FT_PRINTF = FT_PRINTF/libftprintf.a

SOURC_UTILS = ./utils/ft_atoi.c \
			  ./utils/ft_strlen.c \
			  ./utils/ft_strjoin.c \
			  ./utils/ft_itoa.c \
			  ./utils/ft_calloc.c \
			  ./utils/ft_bzero.c \
			  ./utils/ft_memset.c

SOURC_CLIENT = ./source/client.c

SOURC_CLIENT_BONUS = ./source_bonus/client_bonus.c

SOURC_SERVER = ./source/serveur.c

SOURC_SERVER_BONUS = ./source_bonus/serveur_bonus.c \
					 ./source_bonus/main_server.c

OBJS_UTILS = $(SOURC_UTILS:.c=.o)

OBJS_CLIENT = $(SOURC_CLIENT:.c=.o)

OBJS_SERVER = $(SOURC_SERVER:.c=.o) 

OBJS_CLIENT_BONUS = $(SOURC_CLIENT_BONUS:.c=.o)

OBJS_SERVER_BONUS = $(SOURC_SERVER_BONUS:.c=.o) 

%.o : %.c
	cc $(FLAGS)  -c $< -o $@ 

all : client server

bonus : client_bonus server_bonus

$(FT_PRINTF) :
	make -C ./FT_PRINTF/

client : $(OBJS_CLIENT) $(FT_PRINTF) $(OBJS_UTILS)
	cc $(FLAGS) $(OBJS_CLIENT) $(OBJS_UTILS) $(FT_PRINTF) -o $@
	
server : $(OBJS_SERVER) $(FT_PRINTF) $(OBJS_UTILS)
	cc $(FLAGS) $(OBJS_SERVER) $(OBJS_UTILS) $(FT_PRINTF) -o $@

client_bonus : $(OBJS_CLIENT_BONUS) $(FT_PRINTF) $(OBJS_UTILS)
	cc $(FLAGS) $(OBJS_CLIENT_BONUS) $(OBJS_UTILS) $(FT_PRINTF) -o $@
	
server_bonus : $(OBJS_SERVER_BONUS) $(FT_PRINTF) $(OBJS_UTILS)
	cc $(FLAGS) $(OBJS_SERVER_BONUS) $(OBJS_UTILS) $(FT_PRINTF) -o $@

clean : 
	make clean -C ./FT_PRINTF 
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) 
	$(RM) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS) 
	$(RM) $(OBJS_UTILS)

fclean : clean
	make fclean -C ./FT_PRINTF
	$(RM) client server client_bonus server_bonus

re : fclean all

.PHONY : re fclean clean 

