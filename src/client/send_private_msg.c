/*
** send_private_msg.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Jun  7 11:09:24 2017 Gregoire Renard
** Last update Fri Jun  9 11:24:15 2017 Gregoire Renard
*/

#include "client.h"

static int	send_text(t_client * const client)
{
  int		cpt;

  cpt = 2;
  while (client->map[cpt] != NULL)
    {
      if ((write_safe(client->fd_server, client->map[cpt],
		      strlen(client->map[cpt]))) == -1)
	return (ERROR);
      if (client->map[cpt + 1] != NULL)
	if ((write_safe(client->fd_server, " ", 1)) == -1)
	  return (ERROR);
      cpt++;
    }
  if ((write_safe(client->fd_server, "\r\n", 2)) == -1)
    return (ERROR);
  return (SUCCESS);
}

int		send_private_msg(t_client * const client)
{
  if ((write_safe(client->fd_server, "privmsg ", 8)) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, client->map[1],
	     strlen(client->map[1]))) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, " :", 2)) == -1)
    return (ERROR);
  if ((send_text(client)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
