/*
** server.h for  in /home/renard_e/2/systeme_unix_reseaux/PSU_2016_myirc/include
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon May 22 09:40:53 2017 Gregoire Renard
** Last update Fri Jun  9 17:03:27 2017 Gregoire Renard
*/

#ifndef SERVER_H_
#define SERVER_H_

# include <sys/select.h>
# include <sys/time.h>
# include "commun.h"

# define MAX_QUEUE 42
# define MAX_CMD 13
# define MAX_CHAR 14
# define TMP_CHANNEL "tmpchannelme"

# define MORE_ARG "461 ERR_NEEDMOREPARAMS"
# define USER_OK "300 RPL_NONE"
# define AUTH_OK "001 :"
# define ALREADY_REG "462 ERR_ALREADYREGISTRED"
# define NO_NICKNAME "431 ERR_NONICKNAMEGIVEN"
# define NAME_DOUBLE "433 ERR_NICKNAMEINUSE"
# define NO_SERVER "402 ERR_NOSUCHSERVER"
# define RPL_LIST "322 RPL_LIST"
# define RPL_LISTSTART "321 RPL_LISTSTART"
# define RPL_LISTEND "323 RPL_LISTEND"
# define NOSUCHCHANNEL "403 ERR_NOSUCHCHANNEL"
# define RPL_TOPIC "332 RPL_TOPIC"
# define END "Good Bye my friend !"
# define NOTONCHANNEL "442 ERR_NOTONCHANNEL"
# define RPL_STARTUSERS "392 RPL_STARTUSERS"
# define RPL_USERS "393 RPL_USERS"
# define RPL_ENDUSERS "394 RPL_ENDUSERS"
# define ERR_NOSUCHSERVER "402 ERR_NOSUCHSERVER"
# define ERR_BADCHANMASK "476 ERR_BADCHANMASK"
# define ERR_CANNOTSENDTOCHAN "404 ERR_CANNOTSENDTOCHAN"
# define RPL_AWAY "301 RPL_AWAY"
# define ERR_NOTEXTTOSEND "412 ERR_NOTEXTTOSEND"
# define ERR_TOOMANYTARGETS "407 ERR_TOOMANYTARGETS"
# define ERR_NOSUCHNICK "401 ERR_NOSUCHNICK"
# define ERR_CMD "421 ERR_UNKNOWNCOMMAND"
# define NO_TOPIC "331 RPL_NOTOPIC"
# define RPL_NAMREPLY "353 RPL_NAMREPLY: "

typedef struct s_server t_server;

typedef struct		s_connect
{
  int			pass;
  int			user;
}			t_connect;

typedef struct		s_user
{
  char			*name;
  int			fd_user;
  int			accept_data;
  t_connect		connect;
  struct s_user		*next;
  struct s_user		*prev;
}			t_user;

typedef struct		s_channel
{
  t_user		*user_list;
  char			*name;
  struct s_channel	*next;
  struct s_channel	*prev;
}			t_channel;

typedef struct		s_select
{
  int			max_fd;
  fd_set		readfds;
  int			error;
}			t_select;

typedef struct	s_pointer
{
  char		*cmd;
  int		(*func)(t_server * const server,
			t_user * const user);
}		t_pointer;

typedef struct		s_server
{
  int			fd_server;
  struct protoent	*pe;
  struct sockaddr_in	s_in_server;
  t_channel		*channel;
  t_channel		*tmp;
  t_pointer		tab[MAX_CMD];
  char			**map;
  char			*msg;
}			t_server;

int			init_info(char **argv, t_info * const info);
int			start_server(t_info * const info);
int			add_channel(t_channel **channel, char *name);
int			add_user_to_channel(t_user **user_list,
					    char *user_name,
					    int fd_user);
void			free_channels(t_channel *channel);
int			remove_user(t_user **head_of_user,
				    t_user *user_to_remove);
int			remove_channel(t_channel **channel, t_channel *remove);
void			print_all_channels(t_channel *channel);
int			start_com(t_server * const server,
				  t_info * const info);
int			check_all(t_server * const server,
				  t_select * const select);
int			add_client(t_server * const server,
				   t_select * const select);
int			init_func(t_server * const server);
int			server_func(t_server * const server,
				    t_user * const user);
int			nick_func(t_server * const server,
				  t_user * const user);
int			list_func(t_server * const server,
				  t_user * const user);
int			join_func(t_server * const server,
				  t_user * const user);
int			part_func(t_server * const server,
				  t_user * const user);
int			users_func(t_server * const server,
				   t_user * const user);
int			names_func(t_server * const server,
				   t_user * const user);
int			privmsg_func(t_server * const server,
				     t_user * const user);
int			who_func(t_server * const server,
				 t_user * const user);
int			user_func(t_server * const server,
				    t_user * const user);
int			pass_func(t_server * const server,
				    t_user * const user);
int			quit_func(t_server * const server,
				  t_user * const user);
int			message_to_channel(t_server * const server,
					   t_user * const user);
int			treatment(t_server * const server,
				  t_user * const user);
t_channel		*search_channel(t_server * const server);
int			list_channel(t_server * const server,
				     t_user * const user,
				     char *channel);
int			private_message(t_server * const server,
					t_user * const user);
int			send_name(t_user * const user, int fd_target);
int			search_double(t_server * const server,
				      char *name,
				      t_user * const user);
int			real_join(t_server * const server,
				  t_user * const user);
int			real_part(t_server * const server,
				  t_user * const user);
int			real_names(t_server * const server,
				   t_user * const user);
int			check_user(char **map);
int			list_users(t_server * const server,
				   t_user * const user);
int			send_all_message(char **map,
					 int fd_target);
int			real_nick(t_server * const server,
				  t_user * const user);
int			write_safe_all(char **map, int fd);

#endif /* !SERVER_H_ */
