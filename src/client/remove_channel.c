/*
** remove_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Jun  8 10:54:10 2017 Gregoire Renard
** Last update Thu Jun  8 13:05:50 2017 Gregoire Renard
*/

#include "client.h"

static int	set_replace(t_client * const client,
			    char ***replace)
{
  int		cpt_ori;
  int		cpt_replace;

  cpt_ori = 0;
  cpt_replace = 0;
  while (client->channel[cpt_ori] != NULL)
    {
      if ((strcmp(client->channel[cpt_ori],
		  client->map[1])) == 0)
	cpt_ori++;
      else
	{
	  if (((*replace)[cpt_replace] =
	       strdup(client->channel[cpt_ori])) == NULL)
	    return (ERROR);
	  cpt_ori++;
	  cpt_replace++;
	}
    }
  (*replace)[cpt_replace] = NULL;
  return (SUCCESS);
}

int		remove_channel(t_client * const client)
{
  int		len;
  char		**replace;

  len = strlen_map(client->channel);
  if ((replace = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (ERROR);
  if ((set_replace(client, &replace)) == ERROR)
    return (ERROR);
  free_map(client->channel);
  client->channel = replace;
  return (SUCCESS);
}
