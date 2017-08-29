/*
** search_double.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/server
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Jun  1 14:01:43 2017 Gregoire Renard
** Last update Wed Jun  7 12:29:05 2017 Gregoire Renard
*/

#include "server.h"

int		search_double(t_server * const server,
			      char *name,
			      t_user * const user)
{
  t_user	*tmp_user;

  tmp_user = server->tmp->user_list;
  while (tmp_user != NULL)
    {
      if (tmp_user->name != NULL)
	if ((strcasecmp(tmp_user->name, name)) == 0
	    && user->fd_user != tmp_user->fd_user)
	  return (SUCCESS);
      tmp_user = tmp_user->next;
    }
  return (ERROR);
}
