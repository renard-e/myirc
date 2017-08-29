/*
** get_ip.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May 28 12:52:54 2017 Gregoire Renard
** Last update Sun May 28 15:58:09 2017 Gregoire Renard
*/

#include "client.h"

static int		fill_ip(t_client * const client,
				int len)
{
  int			cpt;

  if ((client->ip_server = malloc(len + 1)) == NULL)
    return (ERROR);
  cpt = 0;
  while (client->map[1][cpt] != ':')
    {
      client->ip_server[cpt] = client->map[1][cpt];
      cpt++;
    }
  client->ip_server[cpt] = 0;
  return (SUCCESS);
}

static int		count_len_ip(t_client * const client)
{
  int			cpt;

  cpt = 0;
  while (client->map[1][cpt] != ':' &&
	 client->map[1][cpt] != '\0')
    cpt++;
  if (client->map[1][cpt] == '\0')
    return (-1);
  return (cpt);
}

static int		fill_port(t_client * const client,
				  int len)
{
  char			*port;
  int			cpt;

  cpt = len;
  while (client->map[1][cpt] != '\0')
    cpt++;
  if ((port = malloc((cpt - len) + 1)) == NULL)
    return (ERROR);
  cpt = 0;
  len++;
  while (client->map[1][len] != '\0')
    {
      port[cpt] = client->map[1][len];
      len++;
      cpt++;
    }
  port[cpt] = 0;
  if ((strlen(port)) > 6)
    return (ERROR);
  client->port_server = atoi(port);
  free(port);
  return (SUCCESS);
}

int			get_ip(t_client * const client)
{
  int			len;

  if ((len = count_len_ip(client)) == -1)
    return (ERROR);
  if ((fill_ip(client, len)) == ERROR)
    return (ERROR);
  if ((fill_port(client, len)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
