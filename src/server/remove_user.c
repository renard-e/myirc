/*
** remove_user.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 15:06:57 2017 Gregoire Renard
** Last update Fri Jun  2 10:04:43 2017 Gregoire Renard
*/

#include "server.h"

int			remove_user(t_user **head_of_user,
				    t_user *user_to_remove)
{
  t_user		*tmp;

  if (user_to_remove->prev == NULL && user_to_remove->next != NULL)
    (*head_of_user) = (*head_of_user)->next;
  if (user_to_remove->prev == NULL && user_to_remove->next == NULL)
    (*head_of_user) = NULL;
  tmp = user_to_remove;
  if (user_to_remove->prev != NULL)
    user_to_remove->prev->next = user_to_remove->next;
  if (user_to_remove->next != NULL)
    user_to_remove->next->prev = user_to_remove->prev;
  if (tmp->name != NULL)
    free(tmp->name);
  free(tmp);
  return (SUCCESS);
}
