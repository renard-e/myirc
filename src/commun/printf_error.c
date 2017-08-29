/*
** printf_error.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/commun
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 09:44:05 2017 Gregoire Renard
** Last update Tue May 23 16:51:29 2017 Gregoire Renard
*/

#include "commun.h"

int			printf_error(const char *str)
{
  dprintf(2, "%s\n", str);
  return (ERROR);
}
