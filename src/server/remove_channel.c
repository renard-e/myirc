/*
** remove_channel.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 14:53:33 2017 Gregoire Renard
** Last update Wed May 24 16:02:43 2017 Gregoire Renard
*/

#include "server.h"

int			remove_channel(t_channel **channel,
				       t_channel *remove)
{
  t_channel		*tmp;
  t_user		*tmp_user;

  if (remove->prev == NULL)
    (*channel) = (*channel)->next;
  tmp = remove;
  if (remove->prev != NULL)
    remove->prev->next = remove->next;
  if (remove->next != NULL)
    remove->next->prev = remove->prev;
  while (tmp->user_list != NULL)
    {
      tmp_user = tmp->user_list;
      tmp->user_list = tmp->user_list->next;
      close(tmp_user->fd_user);
      free(tmp_user->name);
      free(tmp_user);
    }
  free(tmp->name);
  free(tmp);
  return (SUCCESS);
}
