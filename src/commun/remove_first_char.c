/*
** remove_first_char.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/server
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Jun  1 15:47:07 2017 Gregoire Renard
** Last update Thu Jun  1 15:47:31 2017 Gregoire Renard
*/

#include "server.h"

void		remove_first_char(char **buffer)
{
  int		cpt;

  cpt = 1;
  while ((*buffer)[cpt] != '\0')
    {
      (*buffer)[cpt - 1] = (*buffer)[cpt];
      cpt++;
    }
  (*buffer)[cpt - 1] = 0;
}
