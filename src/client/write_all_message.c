/*
** write_all_message.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Jun  6 12:43:42 2017 Gregoire Renard
** Last update Fri Jun  9 11:27:08 2017 Gregoire Renard
*/

#include "client.h"

int		write_all_message(int fd_target,
				  char **map)
{
  int		cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    {
      if ((write_safe(fd_target, map[cpt],
		      strlen(map[cpt]))) == -1)
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
