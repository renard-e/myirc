/*
** start_server.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 10:38:01 2017 Gregoire Renard
** Last update Fri May 26 14:13:58 2017 Gregoire Renard
*/

#include "server.h"

static int		init_server(t_server * const server,
				    int port)
{
  if ((server->pe = getprotobyname("TCP")) == NULL)
    return (ERROR);
  if ((server->fd_server =
       socket(AF_INET, SOCK_STREAM, server->pe->p_proto)) == -1)
    return (ERROR);
  server->s_in_server.sin_family = AF_INET;
  server->s_in_server.sin_port = htons(port);
  server->s_in_server.sin_addr.s_addr = INADDR_ANY;
  if ((bind(server->fd_server,
	    (const struct sockaddr *)&server->s_in_server,
	    sizeof(server->s_in_server))) == -1)
    {
      close(server->fd_server);
      return (ERROR);
    }
  if ((listen(server->fd_server, MAX_QUEUE)) == -1)
    {
      close(server->fd_server);
      return (ERROR);
    }
  return (SUCCESS);
}

int			start_server(t_info * const info)
{
  t_server		server;

  if ((init_server(&server, info->port)) == ERROR)
    return (printf_error("Server : port already in use"));
  if ((init_func(&server)) == ERROR)
    return (ERROR);
  if ((start_com(&server, info)) == ERROR)
    return (ERROR);
  close(server.fd_server);
  return (SUCCESS);
}
