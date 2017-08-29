/*
** print_all_channels.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 15:22:28 2017 Gregoire Renard
** Last update Wed May 24 18:25:12 2017 Gregoire Renard
*/

#include "server.h"

void			print_all_channels(t_channel *channel)
{
  t_user		*tmp;

  while (channel != NULL)
    {
      printf("nom channel = *%s*\n",
	     channel->name);
      tmp = channel->user_list;
      while (tmp != NULL)
	{
	  printf("\tuser =\t*%s*\tfd = %i\n", tmp->name, tmp->fd_user);
	  tmp = tmp->next;
	}
      channel = channel->next;
    }
}
