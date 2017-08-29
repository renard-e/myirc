/*
** search_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May 28 16:14:17 2017 Gregoire Renard
** Last update Sun May 28 16:18:49 2017 Gregoire Renard
*/

#include "server.h"

t_channel	*search_channel(t_server * const server)
{
  t_channel	*tmp_channel;

  tmp_channel = server->channel;
  while (tmp_channel != NULL)
    {
      if ((strcmp(tmp_channel->name, server->map[1])) == 0)
	return (tmp_channel);
      tmp_channel = tmp_channel->next;
    }
  return (NULL);
}
