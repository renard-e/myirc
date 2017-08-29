/*
** send_name.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 29 14:07:13 2017 Gregoire Renard
** Last update Fri Jun  9 11:17:46 2017 Gregoire Renard
*/

#include "server.h"

int		send_name(t_user * const user,
			  int fd_target)
{
  if ((write_safe(fd_target, user->name, strlen(user->name))) == -1)
    return (ERROR);
  if ((write_safe(fd_target, ": ", 2)) == -1)
    return (ERROR);
  return (SUCCESS);
}

