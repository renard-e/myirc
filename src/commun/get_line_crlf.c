/*
** get_line_crlf.c for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 24 17:21:50 2017 Gregoire Renard
** Last update Wed May 24 17:52:35 2017 Gregoire Renard
*/

#include "commun.h"

static int		add_char(char **buffer, int *cpt, char car)
{
  (*cpt)++;
  if (((*buffer) = realloc((*buffer), *cpt + 1)) == NULL)
    return (ERROR);
  (*buffer)[(*cpt) - 1] = car;
  (*buffer)[(*cpt)] = 0;
  return (SUCCESS);
}

char			*get_line_crlf(int fd_to_read)
{
  char			*buffer;
  char			buf[1];
  int			cpt;
  int			back;

  if ((buffer = malloc(1)) == NULL)
    return (NULL);
  buffer[0] = 0;
  cpt = 0;
  back = 0;
  while (cpt != -1)
    {
      if ((read(fd_to_read, buf, 1)) <= 0)
	return (NULL);
      if (buf[0] == '\r')
	back = 1;
      else if (buf[0] == '\n' && back == 1)
	cpt = -1;
      else
	if ((add_char(&buffer, &cpt, buf[0])) == ERROR)
	  return (NULL);
    }
  return (buffer);
}
