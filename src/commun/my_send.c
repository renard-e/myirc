/*
** my_send.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 24 15:46:41 2017 Gregoire Renard
** Last update Fri Jun  9 11:21:48 2017 Gregoire Renard
*/

#include "commun.h"

int			my_send(int fd_to_send, const char *str)
{
  if ((write_safe(fd_to_send, str, strlen(str))) == -1)
    return (-1);
  if ((write_safe(fd_to_send, "\r\n", 2)) == -1)
    return (-1);
  return (SUCCESS);
}
