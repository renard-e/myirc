/*
** connect_to_server.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May 28 13:17:35 2017 Gregoire Renard
** Last update Sun May 28 13:37:35 2017 Gregoire Renard
*/

#include "client.h"

int			connect_to_server(t_client * const client)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (ERROR);
  if ((client->fd_server = socket(AF_INET,
				  SOCK_STREAM,
				  pe->p_proto)) == -1)
    return (ERROR);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(client->port_server);
  s_in.sin_addr.s_addr = inet_addr(client->ip_server);
  if ((connect(client->fd_server,
	       (struct sockaddr *)&s_in,
	       sizeof(s_in))) == -1)
    return (ERROR);
  return (SUCCESS);
}
