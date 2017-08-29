/*
** real_join.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Jun  2 08:15:03 2017 Gregoire Renard
** Last update Sun Jun 11 15:08:48 2017 Gregoire Renard
*/

#include "server.h"

static int	join_message(t_server * const server,
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

int		real_join(t_server * const server,
			  t_user * const user)
{
  t_channel	*tmp_channel;

  if ((tmp_channel = search_channel(server)) == NULL)
    {
      if ((add_channel(&server->channel, server->map[1])) == ERROR)
	return (ERROR);
      tmp_channel = server->channel;
      while (tmp_channel->next != NULL)
	tmp_channel = tmp_channel->next;
    }
  if ((add_user_to_channel(&tmp_channel->user_list,
			   user->name, user->fd_user)) == ERROR)
    return (ERROR);
  if ((join_message(server, user)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
