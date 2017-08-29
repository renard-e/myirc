/*
** write_safe.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/commun
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Jun  9 10:49:16 2017 Gregoire Renard
** Last update Fri Jun  9 11:32:14 2017 Gregoire Renard
*/

#include "commun.h"

int		write_safe(int fd, const char *str, int len)
{
  int		ret;

  ret = 0;
  while (ret != len)
    {
      len = len - ret;
      if ((ret = write(fd, str + ret, len)) == -1)
	return (-1);
    }
  return (SUCCESS);
}
