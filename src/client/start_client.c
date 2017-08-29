/*
** start_client.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 18:04:15 2017 Gregoire Renard
** Last update Sun Jun 11 15:39:48 2017 Gregoire Renard
*/

#include "client.h"

static int		set_get_client(t_client * const client)
{
  client->ip_server = NULL;
  client->port_server = -1;
  client->name = NULL;
  client->fd_server = -1;
  if ((client->channel = malloc(sizeof(char *) * 1)) == NULL)
    return (ERROR);
  client->channel[0] = NULL;
  return (SUCCESS);
}

static int		read_or_write(t_client * const client)
{
  char			*recv;
  int			ret;

  if (FD_ISSET(client->fd_server, &client->readfds))
    {
      if ((recv = get_line_crlf(client->fd_server)) == NULL)
	return (ERROR);
      printf("<server> : %s\n", recv);
      prompt_func(client);
      free(recv);
    }
  if (FD_ISSET(0, &client->readfds))
    {
      if ((ret = loop_get_line(client)) == ERROR)
	return (ERROR);
      if (ret == QUIT)
	return (SUCCESS);
    }
  if (client->fd_server == -1)
    prompt_func(client);
  return (SUCCESS);
}

static int		choose_one(t_client * const client)
{
  if (client->fd_max - 1 < client->fd_server)
    client->fd_max = client->fd_server + 1;
  if ((client->error = select(client->fd_max,
			      &client->readfds,
			      NULL, NULL, NULL)) == -1)
    return (ERROR);
  return (read_or_write(client));
}

static int		select_func(t_client * const client)
{
  int			ret;

  client->error = 0;
  client->fd_max = 1;
  prompt_func(client);
  while (client->error != -1)
    {
      FD_ZERO(&client->readfds);
      FD_SET(client->fd_server, &client->readfds);
      FD_SET(0, &client->readfds);
      if ((ret = choose_one(client)) == ERROR)
	return (ERROR);
      if (ret == QUIT)
	return (SUCCESS);
    }
  return (SUCCESS);
}

int			start_client(void)
{
  t_client		client;

  if ((set_get_client(&client)) == ERROR)
    return (printf_error("Error: malloc faiur"));
  if ((init_func(&client)) == ERROR)
    return (printf_error("Error: allocation func"));
  if ((select_func(&client)) == ERROR)
    return (ERROR);
  free_map(client.channel);
  return (SUCCESS);
}
