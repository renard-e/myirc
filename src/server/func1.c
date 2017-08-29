/*
** func1.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 26 14:24:50 2017 Gregoire Renard
** Last update Fri Jun  9 16:05:12 2017 Gregoire Renard
*/

#include "server.h"

int		server_func(t_server * const server,
			    t_user * const user)
{
  (void)server;
  (void)user;
  return (SUCCESS);
}

int		nick_func(t_server * const server,
			  t_user * const user)
{
  if (user->connect.pass != -1 && server->map[1] != NULL)
    return (real_nick(server, user));
  else if (server->map[1] == NULL)
    my_send(user->fd_user, NO_NICKNAME);
  return (SUCCESS);
}

int		list_func(t_server * const server,
			  t_user * const user)
{
  if (user->connect.pass != -1 && user->connect.user != -1 &&
      user->name != NULL)
    {
      if (server->map[1] == NULL ||
	  (server->map[1] != NULL && server->map[1][0] == '#'))
	{
	  my_send(user->fd_user, RPL_LISTSTART);
	  if ((list_channel(server, user, server->map[1])) == ERROR)
	    return (ERROR);
	  my_send(user->fd_user, RPL_LISTEND);
	}
      else
	my_send(user->fd_user, ERR_NOSUCHSERVER);
    }
  return (SUCCESS);
}

int		join_func(t_server * const server,
			  t_user * const user)
{
  if (user->connect.pass != -1 && user->connect.user != -1 &&
      user->name != NULL)
    {
      if (server->map[1] != NULL && server->map[1][0] == '#'
	  && server->map[1][1] != '\0')
	return (real_join(server, user));
      else if (server->map[1] == NULL)
	my_send(user->fd_user, MORE_ARG);
      else
	my_send(user->fd_user, ERR_BADCHANMASK);
    }
  return (SUCCESS);
}

int		part_func(t_server * const server,
			  t_user * const user)
{
  if (user->connect.pass != -1 && user->connect.user != -1 &&
      user->name != NULL)
    {
      if (server->map[1] != NULL && server->map[1][0] == '#')
	return (real_part(server, user));
      else if (server->map[1] == NULL)
	my_send(user->fd_user, MORE_ARG);
      else
	my_send(user->fd_user, NOTONCHANNEL);
    }
  return (SUCCESS);
}
