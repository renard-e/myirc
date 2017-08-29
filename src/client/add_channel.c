/*
** add_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Jun  7 15:12:18 2017 Gregoire Renard
** Last update Thu Jun  8 11:35:49 2017 Gregoire Renard
*/

#include "client.h"

int		add_channel(t_client * const client)
{
  int		len;

  len = strlen_map(client->channel);
  if ((client->channel = realloc(client->channel,
				 sizeof(char *) * (len + 2))) == NULL)
    return (ERROR);
  if ((client->channel[len] = strdup(client->map[1])) == NULL)
    return (ERROR);
  client->channel[len + 1] = NULL;
  return (SUCCESS);
}
