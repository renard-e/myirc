/*
** add_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 11:06:40 2017 Gregoire Renard
** Last update Wed May 24 10:56:45 2017 Gregoire Renard
*/

#include "server.h"

static int		set_elem(t_channel **elem,
				 char *name)
{
  (*elem)->next = NULL;
  (*elem)->prev = NULL;
  (*elem)->user_list = NULL;
  if (((*elem)->name = strdup(name)) == NULL)
    return (ERROR);
  return (SUCCESS);
}

int			add_channel(t_channel **channel,
				    char *name)
{
  t_channel		*elem;
  t_channel		*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (ERROR);
  if ((set_elem(&elem, name)) == ERROR)
    return (ERROR);
  if ((*channel) == NULL)
    (*channel) = elem;
  else
    {
      tmp = (*channel);
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (SUCCESS);
}
