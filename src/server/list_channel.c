/*
** list_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 29 12:42:20 2017 Gregoire Renard
** Last update Fri Jun  2 11:07:49 2017 Gregoire Renard
*/

#include "server.h"

static int	try_this_channel(t_user * const user,
				 char *channel,
				 int *change,
				 t_channel *tmp_channel)
{
  if (channel == NULL)
    {
      *change = 1;
      if ((my_send(user->fd_user,
		   tmp_channel->name)) == ERROR)
	return (ERROR);
    }
  else if (((strstr(tmp_channel->name, channel))) != NULL)
    {
      *change = 1;
      if ((my_send(user->fd_user,
		   tmp_channel->name)) == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}

int		list_channel(t_server * const server,
			     t_user * const user,
			     char *channel)
{
  t_channel	*tmp_channel;
  int		change;

  change = 0;
  tmp_channel = server->channel;
  while (tmp_channel != NULL)
    {
      if ((try_this_channel(user, channel,
			    &change, tmp_channel)) == ERROR)
	return (ERROR);
      tmp_channel = tmp_channel->next;
    }
  if (change == 0)
    my_send(user->fd_user, NO_SERVER);
  else
    my_send(user->fd_user, RPL_LIST);
  return (SUCCESS);
}
