/*
** init_info.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 10:28:44 2017 Gregoire Renard
** Last update Mon May 22 10:36:02 2017 Gregoire Renard
*/

#include "server.h"

static int		check_port(char *str)
{
  int			cpt;

  cpt = 0;
  while (str[cpt] != '\0')
    {
      if (str[cpt] < '0' || str[cpt] > '9')
	return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}

int			init_info(char **argv, t_info * const info)
{
  if ((check_port(argv[1])) == ERROR)
    return (ERROR);
  info->port = atoi(argv[1]);
  return (SUCCESS);
}
