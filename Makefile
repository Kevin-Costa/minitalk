##
## Makefile for Makefile in /home/costa_b/rendu/PSU_2013_minitalk
## 
## Made by Kevin Costa
## Login   <costa_b@epitech.net>
## 
## Started on  Mon Mar 17 13:13:15 2014 Kevin Costa
## Last update Wed Jan  7 13:05:44 2015 Kevin Costa
##

CC		=		gcc

SERVER_NAME	=		src_server/server

CLIENT_NAME 	=               src_client/client

CFLAGS  	+=		-Wall -Wextra
CFLAGS		+=		-I .

SERVER_SRCS	=		src_server/main.c	\
				src_server/server.c	\
				my_lib.c		\
				my_lib2.c

CLIENT_SRCS    	=               src_client/client.c	\
				my_lib.c		\
				my_lib2.c

SERVER_OBJS	=		$(SERVER_SRCS:.c=.o)

CLIENT_OBJS 	=               $(CLIENT_SRCS:.c=.o)

all :				$(SERVER_NAME) 		\
				$(CLIENT_NAME)

$(SERVER_NAME) :		$(SERVER_OBJS)
				$(CC)  $(SERVER_OBJS) -o $(SERVER_NAME) $(LDFLAGS)

$(CLIENT_NAME) :		$(CLIENT_OBJS)
				$(CC)  $(CLIENT_OBJS) -o $(CLIENT_NAME) $(LDFLAGS)
clean : 
				rm -rf $(SERVER_OBJS)
				rm -rf $(CLIENT_OBJS)

fclean : 			clean
				rm -rf $(SERVER_NAME)
				rm -rf $(CLIENT_NAME)

re : 				fclean all
