/*
** print_tab.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Jun  8 11:26:03 2017 Gregoire Renard
** Last update Thu Jun  8 11:27:05 2017 Gregoire Renard
*/

#include "client.h"

void		print_tab(char **map)
{
  int		cpt;

  cpt = 0;
  while (map[cpt] != NULL)
    {
      printf("map[%i] = *%s*\n", cpt, map[cpt]);
      cpt++;
    }
}
