/*
** real_nick.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Jun  9 15:50:29 2017 Gregoire Renard
** Last update Sun Jun 11 15:18:15 2017 Gregoire Renard
*/

#include "server.h"

static int	send_change(t_server * const server,
			    t_user * const user)
{
  if ((write_safe(user->fd_user, ":", 1)) == -1)
    return (ERROR);
  if (user->name != NULL)
    if ((write_safe(user->fd_user, user->name,
		    strlen(user->name))) == -1)
      return (ERROR);
  if ((write_safe(user->fd_user, " NICK ", 6)) == -1)
    return (ERROR);
  if ((my_send(user->fd_user, server->map[1])) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		real_nick(t_server * const server,
			  t_user * const user)
{
  int		len;

  while ((search_double(server, server->map[1], user)) == SUCCESS)
    {
      len = strlen(server->map[1]);
      if ((server->map[1] = realloc(server->map[1], len + 2)) == NULL)
	return (ERROR);
      server->map[1][len] = '_';
      server->map[1][len + 1] = 0;
    }
  if ((send_change(server, user)) == ERROR)
    return (ERROR);
  if ((user->name = strdup(server->map[1])) == NULL)
    return (ERROR);
  return (SUCCESS);
}
