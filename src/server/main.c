/*
** main.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 09:47:10 2017 Gregoire Renard
** Last update Wed May 24 18:24:24 2017 Gregoire Renard
*/

#include "server.h"

int			main(int argc, char **argv)
{
  t_info		info;

  if (argc != 2)
    return (printf_error("Usage : ./server port"));
  else if ((strcmp(argv[1], "--help")) == 0)
    printf("Usage : ./server port\n");
  else
    {
      if ((init_info(argv, &info)) == ERROR)
	return (printf_error("Server : bad port"));
      if ((start_server(&info)) == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}
