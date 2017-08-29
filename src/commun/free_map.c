/*
** free_map.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 24 11:49:07 2017 Gregoire Renard
** Last update Thu Jun  1 09:34:30 2017 Gregoire Renard
*/

#include "commun.h"

void		free_map(char **map)
{
  int		cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    {
      free(map[cpt]);
      cpt++;
    }
  free(map);
}
