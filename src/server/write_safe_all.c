/*
** write_safe_all.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Jun  9 17:04:03 2017 Gregoire Renard
** Last update Fri Jun  9 17:15:48 2017 Gregoire Renard
*/

#include "server.h"

static void	upper_cmd(char ***map)
{
  int		cpt;

  cpt = 0;
  while ((*map)[0][cpt] != '\0')
    {
      if ((*map)[0][cpt] >= 'a' &&
	  (*map)[0][cpt] <= 'z')
	(*map)[0][cpt] = (*map)[0][cpt] - 32;
      cpt++;
    }
}

int		write_safe_all(char **map,
			       int fd)
{
  int		cpt;

  cpt = 0;
  upper_cmd(&map);
  if ((write_safe(fd, " ", 1)) == -1)
    return (ERROR);
  while (map[cpt] != NULL)
    {
      if ((write_safe(fd,
		      map[cpt], strlen(map[cpt]))) == -1)
	return (ERROR);
      if (map[cpt + 1] != NULL)
	if ((write_safe(fd, " ", 1)) == -1)
	  return (ERROR);
      cpt++;
    }
  if ((write_safe(fd, "\r\n", 2)) == -1)
    return (ERROR);
  return (SUCCESS);
}
