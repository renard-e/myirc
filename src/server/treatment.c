/*
** treatment.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 26 14:42:40 2017 Gregoire Renard
** Last update Mon Jun  5 18:39:46 2017 Gregoire Renard
*/

#include "server.h"

static int	init_map(t_server * const server,
			 t_user * const user)
{
  char		*buffer;

  if ((buffer = get_line_crlf(user->fd_user)) == NULL)
    return (ERROR);
  if (buffer[0] == '/')
    remove_first_char(&buffer);
  if ((server->map = my_str_to_wordtab(buffer)) == NULL)
    return (ERROR);
  if ((server->msg = strdup(buffer)) == NULL)
    return (ERROR);
  printf("msg = *%s*\n", server->msg);
  free(buffer);
  return (SUCCESS);
}

static int	loop_cmd(t_server * const server,
			 t_user * const user)
{
  int		cpt;

  cpt = 0;
  while (cpt != MAX_CMD)
    {
      if ((strcasecmp(server->map[0], server->tab[cpt].cmd)) == 0)
	{
	  if ((server->tab[cpt].func(server, user)) == ERROR)
	    return (ERROR);
	  return (SUCCESS);
	}
      cpt++;
    }
  if ((my_send(user->fd_user, ERR_CMD)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int		treatment(t_server * const server,
			  t_user * const user)
{
  if ((init_map(server, user)) == ERROR)
    return (ERROR);
  if (server->map[0] != NULL)
    if ((loop_cmd(server, user)) == ERROR)
      return (ERROR);
  free_map(server->map);
  server->map = NULL;
  free(server->msg);
  return (SUCCESS);
}
