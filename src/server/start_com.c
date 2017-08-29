/*
** start_com.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 15:31:38 2017 Gregoire Renard
** Last update Fri Jun  2 16:06:59 2017 Gregoire Renard
*/

#include "server.h"

static void		set_tmp_channel(t_server * const server,
					t_select * const selects)
{
  t_user		*tmp;

  FD_SET(server->fd_server, &selects->readfds);
  tmp = server->tmp->user_list;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd_user, &selects->readfds);
      tmp = tmp->next;
    }
}

static int		set_selects_server(t_select * const selects,
					   t_server * const server)
{
  selects->max_fd = server->fd_server + 1;
  selects->error = 0;
  server->channel = NULL;
  server->tmp = NULL;
  if ((add_channel(&server->tmp, TMP_CHANNEL)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int			start_com(t_server * const server,
				  t_info * const info)
{
  t_select		selects;

  (void)info;
  if ((set_selects_server(&selects, server)) == ERROR)
    return (ERROR);
  while (selects.error != -1)
    {
      FD_ZERO(&selects.readfds);
      set_tmp_channel(server, &selects);
      if ((selects.error = select(selects.max_fd,
				  &selects.readfds,
				  NULL, NULL, NULL)) != -1)
	if ((check_all(server, &selects)) == ERROR)
	  selects.error = -1;
      print_all_channels(server->tmp);
    }
  free_channels(server->channel);
  if (selects.error == -1)
    return (ERROR);
  return (SUCCESS);
}
