/*
** prompt_func.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu May 25 11:17:51 2017 Gregoire Renard
** Last update Thu May 25 11:19:38 2017 Gregoire Renard
*/

#include "client.h"

void		prompt_func(t_client * const client)
{
  write(1, "<", 1);
  if (client->name != NULL)
    write(1, client->name, strlen(client->name));
  else
    write(1, "?", 1);
  write(1, ">: ", 3);
}
