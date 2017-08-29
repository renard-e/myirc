/*
** real_part.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Jun  2 10:19:42 2017 Gregoire Renard
** Last update Sun Jun 11 15:09:53 2017 Gregoire Renard
*/

#include "server.h"

static int	part_channel_msg(t_server * const server,
				 t_user * const user)
{
  if ((write_safe(user->fd_user, ":", 1)) == -1
      || (write_safe(user->fd_user, user->name,
		     strlen(user->name))) == -1)
    return (ERROR);
  if ((write_safe_all(server->map, user->fd_user)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

static int	search_user_part(t_server * const server,
				 t_user * const user,
				 t_channel *tmp_channel)
{
  t_user	*tmp_user;

  tmp_user = tmp_channel->user_list;
  while (tmp_user != NULL &&
	 tmp_user->fd_user != user->fd_user)
    tmp_user = tmp_user->next;
  if (tmp_user != NULL)
    {
      if ((part_channel_msg(server, user)) == ERROR)
	return (ERROR);
      if ((remove_user(&tmp_channel->user_list,
		       tmp_user)) == ERROR)
	return (ERROR);
    }
  else
    if ((my_send(user->fd_user, NOTONCHANNEL)) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

int		real_part(t_server * const server,
			  t_user * const user)
{
  t_channel	*tmp_channel;

  if ((tmp_channel = search_channel(server)) != NULL)
    {
      if ((search_user_part(server, user,
			    tmp_channel)) == ERROR)
	return (ERROR);
    }
  else
    my_send(user->fd_user, NOSUCHCHANNEL);
  return (SUCCESS);
}
