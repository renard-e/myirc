/*
** free_channels.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 12:30:53 2017 Gregoire Renard
** Last update Wed May 24 16:02:23 2017 Gregoire Renard
*/

#include "server.h"

void			free_channels(t_channel *channel)
{
  t_user		*tmp_user;
  t_channel		*tmp_channel;

  while (channel != NULL)
    {
      while (channel->user_list != NULL)
	{
	  tmp_user = channel->user_list;
	  channel->user_list = channel->user_list->next;
	  close(tmp_user->fd_user);
	  free(tmp_user->name);
	  free(tmp_user);
	}
      tmp_channel = channel;
      channel = channel->next;
      free(tmp_channel->name);
      free(tmp_channel);
    }
}
