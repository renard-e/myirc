/*
** get_ip_port.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May 28 12:44:55 2017 Gregoire Renard
** Last update Sun May 28 12:56:56 2017 Gregoire Renard
*/

#include "client.h"

static int		check_server_cmd(t_client * const client)
{
  int			cpt;

  cpt = 0;
  while (client->map[1][cpt] != '\0')
    {
      if ((client->map[1][cpt] < '0' || client->map[1][cpt] > '9')
	  && client->map[1][cpt] != ':' && client->map[1][cpt] != '.')
	return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}

int			get_ip_port(t_client * const client)
{
  if ((check_server_cmd(client)) == ERROR)
    return (ERROR);
  if ((get_ip(client)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
