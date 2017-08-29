/*
** msg_func.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src/client
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Jun  5 12:22:29 2017 Gregoire Renard
** Last update Wed Jun  7 11:44:25 2017 Gregoire Renard
*/

#include "client.h"

static int	ident_exec_cmd(t_client * const client)
{
  if (client->map[1][0] != '#')
    {
      if ((send_private_msg(client)) == ERROR)
	return (ERROR);
    }
  else
    if ((send_file(client)) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

int		msg_func(t_client * const client)
{
  int		len;

  if (client->fd_server != -1)
    {
      len = strlen_map(client->map);
      if (len >= 3)
	{
	  if ((ident_exec_cmd(client)) == ERROR)
	    return (ERROR);
	}
      else
	{
	  dprintf(2, "Usage : /msg $nick $message\n");
	  dprintf(2, "Usage : /msg $channel $nick $file\n");
	}
    }
  else
    dprintf(2, "Error: Login before send command\n");
  return (SUCCESS);
}
