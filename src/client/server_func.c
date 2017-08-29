/*
** func1.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 24 12:12:23 2017 Gregoire Renard
** Last update Fri Jun  9 11:24:54 2017 Gregoire Renard
*/

#include "client.h"

static int	send_info_server(t_client * const client)
{
  if ((write_safe(client->fd_server, "nick ", 5)) == -1)
    return (ERROR);
  if ((my_send(client->fd_server, client->name)) == ERROR)
    return (ERROR);
  if ((write_safe(client->fd_server, "user ", 5)) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, client->name,
		  strlen(client->name))) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, " ", 1)) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, client->ip_server,
		  strlen(client->ip_server))) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, " ", 1)) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, client->ip_server,
		  strlen(client->ip_server))) == -1)
    return (ERROR);
  if ((write_safe(client->fd_server, " :", 2)) == -1)
    return (ERROR);
  if ((my_send(client->fd_server, client->name)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		server_func(t_client * const client)
{
  if (client->map[1] != NULL && client->name != NULL)
    {
      if (client->ip_server != NULL)
	free(client->ip_server);
      if ((get_ip_port(client)) == ERROR)
	dprintf(2, "ERROR : can't find server or port\n");
      else if ((connect_to_server(client)) == ERROR)
	{
	  client->fd_server = -1;
	  dprintf(2, "ERROR : can't find server or port\n");
	}
      else
	if ((send_info_server(client)) == ERROR)
	  return (ERROR);
    }
  else
    dprintf(2, "ERROR: need name for /server use /nick $name\n");
  return (SUCCESS);
}
