/*
** send_all_message.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jun  5 18:49:39 2017 Gregoire Renard
** Last update Fri Jun  9 16:53:39 2017 Gregoire Renard
*/

#include "server.h"

int		send_all_message(char **map,
				 int fd_target)
{
  int		cpt;

  cpt = 2;
  while (map[cpt] != NULL)
    {
      if (cpt == 2)
	remove_first_char(&map[cpt]);
      if ((write_safe(fd_target, map[cpt], strlen(map[cpt]))) == -1)
	return (ERROR);
      if (map[cpt + 1] != NULL)
	if ((write_safe(fd_target, " ", 1)) == -1)
	  return (ERROR);
      cpt++;
    }
  if ((write_safe(fd_target, "\r\n", 2)) == -1)
    return (ERROR);
  return (SUCCESS);
}
