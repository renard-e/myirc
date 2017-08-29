/*
** message_to_all_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/client
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Jun  6 15:06:51 2017 Gregoire Renard
** Last update Fri Jun  9 11:22:05 2017 Gregoire Renard
*/

#include "client.h"

int		message_to_all_channel(t_client * const client)
{
  int		cpt;

  cpt = 0;
  while (client->channel[cpt] != NULL)
    {
      if ((write_safe(client->fd_server, "privmsg ", 8)) == -1)
	return (ERROR);
      if ((write_safe(client->fd_server, client->channel[cpt],
		      strlen(client->channel[cpt]))) == -1)
	return (ERROR);
      if ((write_safe(client->fd_server, " :", 2)) == -1)
	return (ERROR);
      if ((write_all_message(client->fd_server,
			     client->map)) == ERROR)
	return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}
