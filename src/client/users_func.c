/*
** users_func.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/client
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jun  5 12:13:20 2017 Gregoire Renard
** Last update Tue Jun  6 14:38:26 2017 Gregoire Renard
*/

#include "client.h"

int		users_func(t_client * const client)
{
  if (client->fd_server != -1)
    {
      remove_first_char(&client->map[0]);
      if ((write_all_message(client->fd_server,
			     client->map)) == ERROR)
	return (ERROR);
    }
  else if (client->fd_server == -1)
    dprintf(2, "Error: Login before send command\n");
  return (SUCCESS);
}
