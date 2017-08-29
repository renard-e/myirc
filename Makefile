##
## Makefile for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc
## 
## Made by Gregoire Renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon May 22 08:49:41 2017 Gregoire Renard
## Last update Sun Jun 11 15:36:46 2017 Gregoire Renard
##

CC		=	gcc -Iinclude/ -g3

RM		=	rm -fr

SRCS_CLIENT	=	src/client/main.c \
			src/commun/printf_error.c \
			src/client/start_client.c \
			src/client/treatment.c \
			src/commun/my_str_to_wordtab.c \
			src/client/server_func.c \
			src/client/nick_func.c \
			src/commun/free_map.c \
			src/client/prompt_func.c \
			src/client/get_ip_port.c \
			src/client/get_ip.c \
			src/client/connect_to_server.c \
			src/commun/my_send.c \
			src/commun/remove_first_char.c \
			src/client/init_func.c \
			src/client/list_func.c \
			src/client/join_func.c \
			src/client/part_func.c \
			src/client/users_func.c \
			src/client/names_func.c \
			src/client/msg_func.c \
			src/client/accept_func.c \
			src/client/write_all_message.c \
			src/client/message_to_all_channel.c \
			src/commun/strlen_map.c \
			src/client/send_private_msg.c \
			src/client/send_file.c \
			src/client/loop_get_line.c \
			src/client/add_channel.c \
			src/client/remove_channel.c \
			src/client/print_tab.c \
			src/commun/get_line_crlf.c \
			src/commun/write_safe.c \

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

SRCS_SERVER	=	src/server/main.c \
			src/commun/printf_error.c \
			src/server/init_info.c \
			src/server/start_server.c \
			src/server/add_channel.c \
			src/server/add_user_to_channel.c \
			src/server/free_channels.c \
			src/server/remove_channel.c \
			src/server/remove_user.c \
			src/server/print_all_channels.c \
			src/server/start_com.c \
			src/commun/my_send.c \
			src/server/check_all.c \
			src/server/add_client.c \
			src/commun/get_line_crlf.c \
			src/server/init_func.c \
			src/server/func1.c \
			src/server/func2.c \
			src/server/treatment.c \
			src/server/message_to_channel.c \
			src/commun/free_map.c \
			src/commun/my_str_to_wordtab.c \
			src/server/search_channel.c \
			src/server/list_channel.c \
			src/server/private_message.c \
			src/server/send_name.c \
			src/server/func3.c \
			src/server/quit_func.c \
			src/server/search_double.c \
			src/commun/remove_first_char.c \
			src/server/real_join.c \
			src/server/check_user.c \
			src/server/real_part.c \
			src/server/real_names.c \
			src/server/list_users.c \
			src/server/send_all_message.c \
			src/commun/strlen_map.c \
			src/commun/write_safe.c \
			src/server/real_nick.c \
			src/server/write_safe_all.c \

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

SERVER_NAME	=	server

CLIENT_NAME	=	client

CFLAGS		=	-W -Wall -Werror -Wextra

all		:	server client

re		:	fclean all

server		:	$(OBJS_SERVER)
			$(CC) -o $(SERVER_NAME) $(SRCS_SERVER)

client		:	$(OBJS_CLIENT)
			$(CC) -o $(CLIENT_NAME) $(SRCS_CLIENT)

clean		:
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)

fclean		:	clean
			$(RM) $(SERVER_NAME)
			$(RM) $(CLIENT_NAME)

.PHONY		: all re clean fclean
