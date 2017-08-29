/*
** list_users.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jun  5 10:25:46 2017 Gregoire Renard
** Last update Mon Jun  5 11:05:06 2017 Gregoire Renard
*/

#include "server.h"

int		list_users(t_server * const server,
			   t_user * const user)
{
  t_user	*tmp_user;

  tmp_user = server->tmp->user_list;
  while (tmp_user != NULL)
    {
      if (server->map[1] == NULL && tmp_user->name != NULL)
	my_send(user->fd_user, tmp_user->name);
      else if (tmp_user->name != NULL &&
	       ((strstr(tmp_user->name, server->map[1])) != NULL))
	my_send(user->fd_user, tmp_user->name);
      tmp_user = tmp_user->next;
    }
  return (SUCCESS);
}
