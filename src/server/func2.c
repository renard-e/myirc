/*
** func2.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 26 14:28:44 2017 Gregoire Renard
** Last update Wed Jun  7 12:29:36 2017 Gregoire Renard
*/

#include "server.h"

int		users_func(t_server * const server,
			   t_user * const user)
{
  t_user	*tmp_user;

  if (user->connect.pass != -1 && user->connect.user != -1 &&
      user->name != NULL)
    {
      my_send(user->fd_user, RPL_STARTUSERS);
      my_send(user->fd_user, RPL_USERS);
      tmp_user = server->tmp->user_list;
      while (tmp_user != NULL)
	{
	  if (tmp_user->name != NULL &&
	      tmp_user->fd_user != user->fd_user)
	    if ((my_send(user->fd_user, tmp_user->name)) == ERROR)
	      return (ERROR);
	  tmp_user = tmp_user->next;
	}
      my_send(user->fd_user, RPL_ENDUSERS);
    }
  return (SUCCESS);
}

int		names_func(t_server * const server,
			   t_user * const user)
{
  if (user->connect.pass != -1 && user->connect.user != -1 &&
      user->name != NULL)
    if (server->map[1] != NULL)
      if ((real_names(server, user)) == ERROR)
	return (ERROR);
  return (SUCCESS);
}

int		privmsg_func(t_server * const server,
			     t_user * const user)
{
  if (user->connect.pass != -1 && user->connect.user != -1 &&
      user->name != NULL)
    {
      if (server->map[1] != NULL && server->map[2] == NULL)
	return (my_send(user->fd_user, ERR_NOTEXTTOSEND));
      else if (server->map[1] != NULL && server->map[2] != NULL
	       && server->map[2][0] != ':')
	return (my_send(user->fd_user, ERR_TOOMANYTARGETS));
      else if (server->map[1] != NULL && server->map[1][0] != '#')
	return (private_message(server, user));
      else if (server->map[1] != NULL && server->map[1][0] == '#')
	return (message_to_channel(server, user));
    }
  return (SUCCESS);
}

int		who_func(t_server * const server,
			 t_user * const user)
{
  if (user->connect.pass != -1 && user->connect.user != -1 &&
      user->name != NULL)
    if ((list_users(server, user)) == ERROR)
      return (ERROR);
  return (SUCCESS);
}
