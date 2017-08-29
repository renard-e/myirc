/*
** real_names.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/server
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Jun  2 12:38:17 2017 Gregoire Renard
** Last update Fri Jun  2 12:51:27 2017 Gregoire Renard
*/

#include "server.h"

int		real_names(t_server * const server,
			   t_user * const user)
{
  t_channel	*tmp_channel;
  t_user	*tmp_user;

  if ((tmp_channel = search_channel(server)) != NULL)
    {
      tmp_user = tmp_channel->user_list;
      while (tmp_user != NULL)
	{
	  if (tmp_user->name != NULL &&
	      tmp_user->fd_user != user->fd_user)
	    if ((my_send(user->fd_user, tmp_user->name)) == ERROR)
	      return (ERROR);
	  tmp_user = tmp_user->next;
	}
    }
  return (SUCCESS);
}
