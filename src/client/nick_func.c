/*
** nick_func.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/client
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 29 17:47:28 2017 Gregoire Renard
** Last update Wed Jun  7 14:48:06 2017 Gregoire Renard
*/

#include "client.h"

int		nick_func(t_client * const client)
{
  if (client->map[1] != NULL)
    {
      if (client->name != NULL)
	free(client->name);
      if ((client->name = strdup(client->map[1])) == NULL)
	return (ERROR);
      if (client->fd_server != -1)
	{
	  remove_first_char(&client->map[0]);
	  if ((write_all_message(client->fd_server,
				 client->map)) == ERROR)
	    return (ERROR);
	}
    }
  return (SUCCESS);
}
