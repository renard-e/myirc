/*
** add_client.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 24 16:10:02 2017 Gregoire Renard
** Last update Wed May 24 16:44:21 2017 Gregoire Renard
*/

#include "server.h"

int			add_client(t_server * const server,
				   t_select * const selects)
{
  int			fd_client;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size_client;

  s_in_size_client = sizeof(s_in_client);
  if ((fd_client =
       accept(server->fd_server,
	      (struct sockaddr *)&s_in_client,
	      &s_in_size_client)) == -1)
    return (ERROR);
  if (fd_client >= selects->max_fd - 1)
    selects->max_fd = fd_client + 1;
  if ((add_user_to_channel(&server->tmp->user_list,
			   NULL, fd_client)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
