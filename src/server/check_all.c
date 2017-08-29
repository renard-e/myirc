/*
** check_all.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 24 15:54:50 2017 Gregoire Renard
** Last update Fri Jun  2 16:06:25 2017 Gregoire Renard
*/

#include "server.h"

static int	send_if_move(t_server * const server,
			     t_select * const select)
{
  t_user	*tmp;
  t_user	*tmp2;

  tmp = server->tmp->user_list;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      tmp = tmp->next;
      if (FD_ISSET(tmp2->fd_user, &select->readfds))
	if ((treatment(server, tmp2)) == ERROR)
	  quit_func(server, tmp2);
    }
  return (SUCCESS);
}

int		check_all(t_server * const server,
			  t_select * const select)
{
  if (FD_ISSET(server->fd_server, &select->readfds))
    if ((add_client(server, select)) == ERROR)
      return (ERROR);
  if ((send_if_move(server, select)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
