/*
** client.c for client in /home/costa_b/rendu/PSU_2013_minitalk/src_client
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Mar 17 13:43:45 2014 Kevin Costa
** Last update Sun Mar 23 15:00:05 2014 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<signal.h>
#include	<unistd.h>
#include	"client.h"
#include	"lib.h"

void		com(int	server, unsigned char msg)
{
  int		i;
  int		nb;

  i = -1;
  nb = msg;
  while (++i < 8)
    {
      if (nb % 2 == 0)
	{
	  if ((kill(server, SIGUSR1)) == -1)
	    my_puterror("Your pid is incorrect\n");
	}
      else
	{
	  if ((kill(server, SIGUSR2)) == -1)
	    my_puterror("Your pid is incorrect\n");
	}
      usleep(1400);
      nb = nb / 2;
    }
}

void		client(char **av)
{
  int		i;
  int		server;

  server = my_getnbr(av[1]);
  if (server <= 0)
    {
      my_putstr("Votre Pid est incorrect\n");
      exit(1);
    }
  i = 0;
  while (av[2][i] != '\0')
    {
      com(server, av[2][i]);
      i++;
    }
  com(server, '\n');
}

int		main(int ac, char **av)
{
  if (ac == 3)
    client(av);
  else
    {
      my_putstr("You need 2 argument:\n- server pid\n- the message\n");
      exit(1);
    }
  return (0);
}
