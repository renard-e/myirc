/*
** commun.h for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/include
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 09:40:44 2017 Gregoire Renard
** Last update Fri Jun  9 11:32:55 2017 Gregoire Renard
*/

#ifndef COMMUN_H_
#define COMMUN_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>

# define ERROR 84
# define SUCCESS 1

typedef struct		s_info
{
  int			port;
  char			*ip;
}			t_info;

typedef struct		s_all
{
  int			size;
  int			cpt;
  int			x;
  int			y;
  char			**map;
}			t_all;

int			printf_error(const char *str);
void			free_map(char **map);
char			**my_str_to_wordtab(const char *str);
int			my_send(int fd_to_send, const char *str);
char			*get_line_crlf(int fd_to_read);
void			remove_first_char(char **buffer);
int			strlen_map(char **map);
int			write_safe(int fd, const char *str, int len);

#endif /* !COMMUN_H_ */
