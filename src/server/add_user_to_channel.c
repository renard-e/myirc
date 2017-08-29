/*
** add_user_to_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 11:35:39 2017 Gregoire Renard
** Last update Thu Jun  1 11:48:37 2017 Gregoire Renard
*/

#include "server.h"

static int		set_elem(t_user **elem,
				 char *user_name,
				 int fd_user)
{
  if (user_name != NULL)
    {
      if (((*elem)->name = strdup(user_name)) == NULL)
	return (ERROR);
    }
  else
    (*elem)->name = NULL;
  (*elem)->fd_user = fd_user;
  (*elem)->next = NULL;
  (*elem)->prev = NULL;
  (*elem)->accept_data = -1;
  (*elem)->connect.pass = 1;
  (*elem)->connect.user = -1;
  return (SUCCESS);
}

int			add_user_to_channel(t_user **user_list,
					    char *user_name,
					    int fd_user)
{
  t_user		*elem;
  t_user		*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (ERROR);
  if ((set_elem(&elem, user_name, fd_user)) == ERROR)
    return (ERROR);
  if ((*user_list) == NULL)
    (*user_list) = elem;
  else
    {
      tmp = (*user_list);
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (SUCCESS);
}
