/*
** func3.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** started on  Wed May 31 14:37:01 2017 Gregoire Renard
** Last update Fri Jun  9 17:05:56 2017 Gregoire Renard
*/

#include "server.h"

static int	set_user(t_server * const server,
			 t_user * const user)
{
  user->connect.user = 1;
  if ((write_safe(user->fd_user, AUTH_OK, strlen(AUTH_OK))) == -1)
    return (ERROR);
  if ((write_safe(user->fd_user, user->name,
		  strlen(user->name))) == -1)
    return (ERROR);
  if ((write_safe_all(server->map, user->fd_user)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

static int	attribut_name(t_server * const server,
			      t_user * const user)
{
  if ((check_user(server->map)) == SUCCESS)
    return (set_user(server, user));
  else
    my_send(user->fd_user, MORE_ARG);
  return (SUCCESS);
}

int		user_func(t_server * const server,
			  t_user * const user)
{
  int		len;

  len = strlen_map(server->map);
  if (len == 5 && user->connect.user != 1 && user->name != NULL)
    {
      if ((attribut_name(server, user)) == ERROR)
	return (ERROR);
    }
  else if (len == 5 && user->connect.user == 1)
    my_send(user->fd_user, ALREADY_REG);
  else
    my_send(user->fd_user, MORE_ARG);
  return (SUCCESS);
}

int		pass_func(t_server * const server,
			  t_user * const user)
{
  (void)server;
  if (user->connect.pass != 1)
    user->connect.pass = 1;
  else
    my_send(user->fd_user, ALREADY_REG);
  return (SUCCESS);
}
