/*
** treatment.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 24 11:14:53 2017 Gregoire Renard
** Last update Fri Jun  9 12:11:22 2017 Gregoire Renard
*/

#include "client.h"

static int		set_map(t_client * const client,
				t_get_line * const get)
{
  if ((client->map = my_str_to_wordtab(get->line)) == NULL)
    return (ERROR);
  return (SUCCESS);
}

static int		loop_treatment(t_client * const client)
{
  int			cpt;
  int			stop;

  cpt = 0;
  stop = 0;
  while (cpt != MAX_CMD && stop != 1)
    {
      if ((strcasecmp(client->map[0], client->tab[cpt].cmd)) == 0)
	{
	  if ((client->tab[cpt].func(client)) == ERROR)
	    return (ERROR);
	  stop = 1;
	}
      cpt++;
    }
  if (stop != 1)
    if ((message_to_all_channel(client)) == ERROR)
      return (ERROR);
  return (SUCCESS);
}

int			treatment(t_client * const client,
				  t_get_line * const get)
{
  if ((set_map(client, get)) == ERROR)
    return (ERROR);
  if (client->map[0] != NULL)
    if ((loop_treatment(client)) == ERROR)
      return (ERROR);
  free_map(client->map);
  return (SUCCESS);
}
