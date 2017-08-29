/*
** message_to_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 26 14:47:03 2017 Gregoire Renard
** Last update Mon Jun  5 18:47:35 2017 Gregoire Renard
*/

#include "server.h"

static int	message_to_this(t_channel * const this,
				t_server * const server,
				t_user * const user)
{
  t_user	*tmp_user;

  tmp_user = this->user_list;
  while (tmp_user != NULL)
    {
      if (tmp_user->fd_user != user->fd_user)
	{
	  if (user->name != NULL)
	    if ((send_name(user, tmp_user->fd_user)) == ERROR)
	      return (ERROR);
	  if ((send_all_message(server->map,
				tmp_user->fd_user)) == ERROR)
	    return (ERROR);
	}
      tmp_user = tmp_user->next;
    }
  return (SUCCESS);
}

static int	search_user_in_this(t_channel *tmp_channel,
				    t_user * const user,
				    t_server * const server,
				    int *stop)
{
  t_user	*tmp_user;

  tmp_user = tmp_channel->user_list;
  while (tmp_user != NULL && *stop != 1)
    {
      if (tmp_user->fd_user == user->fd_user)
	{
	  my_send(user->fd_user, RPL_AWAY);
	  if ((message_to_this(tmp_channel, server,
			       user)) == ERROR)
	    return (ERROR);
	  *stop = 1;
	}
      tmp_user = tmp_user->next;
    }
  return (SUCCESS);
}

int		message_to_channel(t_server * const server,
				   t_user * const user)
{
  t_channel	*tmp_channel;
  int		stop;

  stop = 0;
  if ((tmp_channel = search_channel(server)) != NULL)
    {
      if ((search_user_in_this(tmp_channel,
			       user, server, &stop)) == ERROR)
	return (ERROR);
    }
  if (tmp_channel == NULL)
    my_send(user->fd_user, NOSUCHCHANNEL);
  else if (stop == 0)
    my_send(user->fd_user, ERR_CANNOTSENDTOCHAN);
  return (SUCCESS);
}
