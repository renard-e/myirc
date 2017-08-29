/*
** check_user.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Jun  2 09:23:19 2017 Gregoire Renard
** Last update Fri Jun  2 09:59:12 2017 Gregoire Renard
*/

#include "server.h"

int		check_user(char **map)
{
  if (map[4][0] != ':')
    return (ERROR);
  return (SUCCESS);
}
