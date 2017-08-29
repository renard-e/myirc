/*
** strlen_map.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Jun  7 10:22:41 2017 Gregoire Renard
** Last update Wed Jun  7 10:23:46 2017 Gregoire Renard
*/

#include "client.h"

int		strlen_map(char **map)
{
  int		cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    cpt++;
  return (cpt);
}
