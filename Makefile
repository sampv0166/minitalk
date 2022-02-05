CC = gcc

CFLAGS = -Wall -Wextra -Werror

SERVER = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

SRCS = server.c helper_functions.c client.c

OBJ = $(SRCS:.c=.o)

BNS_SRCS = server_bonus.c helper_functions_bonus.c client_bonus.c

BNS_OBJ = $(BNS_SRCS:.c=.o)

all  : server client

bonus : server_bonus client_bonus

server : $(OBJ)
		$(CC) $(CFLAGS) server.o helper_functions.o -o $(SERVER)

client : $(OBJ)
		$(CC) $(CFLAGS) client.o helper_functions.o -o $(CLIENT)

server_bonus : $(BNS_OBJ)
		$(CC) $(CFLAGS) server_bonus.o helper_functions_bonus.o -o $(SERVER_BONUS)

client_bonus : $(BNS_OBJ)
		$(CC) $(CFLAGS) client_bonus.o helper_functions_bonus.o -o $(CLIENT_BONUS)

clean :
		rm -rf *.o server client server_bonus client_bonus
		
fclean :clean

re : fclean all
		