/*
** init_func.c<server> for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 26 14:15:36 2017 Gregoire Renard
** Last update Wed Jun  7 13:58:42 2017 Gregoire Renard
*/

#include "server.h"

static void		init_pointer2(t_server * const server)
{
  server->tab[6].func = &names_func;
  server->tab[7].cmd = "privmsg";
  server->tab[7].func = &privmsg_func;
  server->tab[8].cmd = "who";
  server->tab[8].func = &who_func;
  server->tab[9].cmd = "user";
  server->tab[9].func = &user_func;
  server->tab[10].cmd = "pass";
  server->tab[10].func = &pass_func;
  server->tab[11].cmd = "quit";
  server->tab[11].func = &quit_func;
  server->tab[12].cmd = "notice";
  server->tab[12].func = &privmsg_func;
}

static void		init_pointer(t_server * const server)
{
  server->tab[0].cmd = "server";
  server->tab[0].func = &server_func;
  server->tab[1].cmd = "nick";
  server->tab[1].func = &nick_func;
  server->tab[2].cmd = "list";
  server->tab[2].func = &list_func;
  server->tab[3].cmd = "join";
  server->tab[3].func = &join_func;
  server->tab[4].cmd = "part";
  server->tab[4].func = &part_func;
  server->tab[5].cmd = "users";
  server->tab[5].func = &users_func;
  server->tab[6].cmd = "names";
  init_pointer2(server);
}

static int		init_cmd(t_server * const server)
{
  int			cpt;

  cpt = 0;
  while (cpt != MAX_CMD)
    {
      if ((server->tab[cpt].cmd = malloc(MAX_CHAR)) == NULL)
	return (ERROR);
      cpt++;
    }
  return (SUCCESS);
}

int		init_func(t_server * const server)
{
  if ((init_cmd(server)) == ERROR)
    return (ERROR);
  init_pointer(server);
  return (SUCCESS);
}
