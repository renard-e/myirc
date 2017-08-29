/*
** loop_get_line.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Jun  7 14:15:43 2017 Gregoire Renard
** Last update Fri Jun  9 12:10:49 2017 Gregoire Renard
*/

#include "client.h"

static int	quit_func(t_client * const client)
{
  if ((my_send(client->fd_server, "quit")) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		loop_get_line(t_client * const client)
{
  t_get_line	get;

  get.size = 0;
  if ((get.ret = getline(&get.line, &get.size, stdin)) < 0)
    return (ERROR);
  get.line[get.ret - 1] = 0;
  if ((strcasecmp(get.line, "quit")) == 0)
    {
      quit_func(client);
      return (QUIT);
    }
  if ((get.ret = treatment(client, &get)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
