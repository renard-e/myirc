/*
** main.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 09:46:02 2017 Gregoire Renard
** Last update Wed May 24 10:53:07 2017 Gregoire Renard
*/

#include "client.h"

int			main(void)
{
  if ((start_client()) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
