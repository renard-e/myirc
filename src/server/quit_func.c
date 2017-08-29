/*
** quit_func.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/server
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 31 14:56:39 2017 Gregoire Renard
** Last update Thu Jun  8 13:16:54 2017 Gregoire Renard
*/

#include "server.h"

static void	remove_tmp_channel(t_server * const server,
				   t_user * const user)
{
  if (server->map == NULL || server->map[1] == NULL)
    my_send(user->fd_user, END);
  else
    {
      if (server->map[1][0] == ':')
	remove_first_char(&server->map[1]);
      my_send(user->fd_user, server->map[1]);
    }
  close(user->fd_user);
  remove_user(&server->tmp->user_list, user);
}

int		quit_func(t_server * const server,
			  t_user * const user)
{
  t_channel	*tmp_channel;
  t_user	*tmp_user;
  int		stop;

  tmp_channel = server->channel;
  while (tmp_channel != NULL)
    {
      tmp_user = tmp_channel->user_list;
      stop = 0;
      while (tmp_user != NULL && stop == 0)
	{
	  if (tmp_user->fd_user == user->fd_user)
	    {
	      if ((remove_user(&tmp_channel->user_list,
			       tmp_user)) == ERROR)
		return (ERROR);
	      stop = 1;
	    }
	  if (stop == 0)
	    tmp_user = tmp_user->next;
	}
      tmp_channel = tmp_channel->next;
    }
  remove_tmp_channel(server, user);
  return (SUCCESS);
}
