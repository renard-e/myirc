/*
** private_message.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 29 13:48:10 2017 Gregoire Renard
** Last update Wed Jun  7 13:56:39 2017 Gregoire Renard
*/

#include "server.h"

static int	try_this_user(t_server * const server,
			      t_user * const user,
			      t_user *tmp_user,
			      int *send)
{
  if (tmp_user->name != NULL)
    {
      if ((strcasecmp(server->map[1], tmp_user->name)) == 0)
	{
	  *send = 1;
	  if (user->name != NULL)
	    if ((send_name(user, tmp_user->fd_user)) == ERROR)
	      return (ERROR);
	  if ((send_all_message(server->map,
				tmp_user->fd_user)) == ERROR)
	    return (ERROR);
	}
    }
  return (SUCCESS);
}

int		private_message(t_server * const server,
				t_user * const user)
{
  t_user	*tmp_user;
  int		send;

  send = 0;
  tmp_user = server->tmp->user_list;
  while (tmp_user != NULL)
    {
      if ((try_this_user(server, user,
			 tmp_user, &send)) == ERROR)
	return (ERROR);
      tmp_user = tmp_user->next;
    }
  if (send == 0 && (strcasecmp(server->map[0], "notice")) != 0)
    my_send(user->fd_user, ERR_NOSUCHNICK);
  else if (send == 1 && (strcasecmp(server->map[0], "notice")) != 0)
    my_send(user->fd_user, RPL_AWAY);
  return (SUCCESS);
}
