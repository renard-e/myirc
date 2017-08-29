/*
** init_client.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 26 12:30:13 2017 Gregoire Renard
** Last update Fri May 26 14:15:05 2017 Gregoire Renard
*/

#include "client.h"

static void		init_pointer(t_client * const client)
{
  client->tab[0].cmd = "/server";
  client->tab[0].func = &server_func;
  client->tab[1].cmd = "/nick";
  client->tab[1].func = &nick_func;
  client->tab[2].cmd = "/list";
  client->tab[2].func = &list_func;
  client->tab[3].cmd = "/join";
  client->tab[3].func = &join_func;
  client->tab[4].cmd = "/part";
  client->tab[4].func = &part_func;
  client->tab[5].cmd = "/users";
  client->tab[5].func = &users_func;
  client->tab[6].cmd = "/names";
  client->tab[6].func = &names_func;
  client->tab[7].cmd = "/msg";
  client->tab[7].func = &msg_func;
  client->tab[8].cmd = "/accept_file";
  client->tab[8].func = &accept_func;
}

static int		init_cmd(t_client * const client)
{
  int			cpt;

  cpt = 0;
  while (cpt != MAX_CMD)
    {
      if ((client->tab[cpt].cmd = malloc(MAX_CHAR)) == NULL)
	return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}

int		init_func(t_client * const client)
{
  if ((init_cmd(client)) == ERROR)
    return (ERROR);
  init_pointer(client);
  return (SUCCESS);
}
