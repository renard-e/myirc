/*
** join_func.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/client
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jun  5 12:22:17 2017 Gregoire Renard
** Last update Fri Jun  9 14:36:20 2017 Gregoire Renard
*/

#include "client.h"

int		join_func(t_client * const client)
{
  if (client->map[1] != NULL &&
      client->map[2] == NULL &&
      client->fd_server != -1 &&
      client->map[1][0] == '#')
    {
      remove_first_char(&client->map[0]);
      if ((write_all_message(client->fd_server,
			     client->map)) == ERROR)
	return (ERROR);
      if ((add_channel(client)) == ERROR)
	return (ERROR);
    }
  else if (client->fd_server == -1)
    dprintf(2, "Error: Login before send command\n");
  else
    dprintf(2, "Error: /join [$name channel]\n");
  return (SUCCESS);
}
