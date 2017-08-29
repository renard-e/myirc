/*
** client.h for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/include
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 09:29:31 2017 Gregoire Renard
** Last update Sun Jun 11 15:36:19 2017 Gregoire Renard
*/

#ifndef CLIENT_H_
#define CLIENT_H_

# include <netinet/in.h>
# include <arpa/inet.h>
# include "commun.h"

# define MAX_CMD 9
# define MAX_CHAR 14
# define QUIT 17

typedef struct	s_client t_client;

typedef struct	s_get_line
{
  size_t	size;
  char		*line;
  ssize_t	ret;
}		t_get_line;

typedef struct	s_pointer
{
  char		*cmd;
  int		(*func)(t_client * const client);
}		t_pointer;

typedef struct	s_client
{
  char		*name;
  char		*ip_server;
  int		port_server;
  int		fd_server;
  char		**map;
  t_pointer	tab[MAX_CMD];
  char		**channel;
  fd_set	readfds;
  int		fd_max;
  int		error;
}		t_client;

int		start_client(void);
int		treatment(t_client * const client,
			  t_get_line * const get);
int		server_func(t_client * const client);
int		nick_func(t_client * const client);
int		list_func(t_client * const client);
int		join_func(t_client * const client);
int		part_func(t_client * const client);
int		users_func(t_client * const client);
int		names_func(t_client * const client);
int		msg_func(t_client * const client);
int		accept_func(t_client * const client);
void		prompt_func(t_client * const client);
int		get_ip_port(t_client * const client);
int		get_ip(t_client * const client);
int		connect_to_server(t_client * const client);
int		init_func(t_client * const client);
int		write_all_message(int fd_target, char **map);
int		message_to_all_channel(t_client * const client);
int		send_private_msg(t_client * const client);
int		send_file(t_client * const client);
int		loop_get_line(t_client * const client);
int		add_channel(t_client * const client);
int		remove_channel(t_client * const client);
void		print_tab(char **map);

#endif /* !CLIENT_H_ */
