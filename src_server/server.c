/*
** server.c for server in /home/costa_b/rendu/PSU_2013_minitalk/src_server
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Mar 17 13:43:57 2014 Kevin Costa
** Last update Fri Mar 21 15:37:35 2014 Kevin Costa
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/types.h>
#include	"server.h"
#include	"lib.h"

char		my_recursive(unsigned char bin[9], int rang)
{
  if (rang == 7)
    return (bin[7] - '0');
  return (bin[rang] - '0' + 2 * my_recursive(bin, rang + 1));
}

void		my_put(unsigned char bin)
{
  static int	i = 0;
  unsigned char	c[9];

  c[i] = bin;
  c[8] = '\0';
  i++;
  if (i > 7)
    {
      my_putchar(my_recursive(c, 0));
      i = 0;
    }
}

void		sig(int sig)
{
  if (sig == SIGUSR1)
    my_put('0');
  if (sig == SIGUSR2)
    my_put('1');
}

void		server()
{
  signal(SIGUSR1, &sig);
  signal(SIGUSR2, &sig);
  my_putstr("Server PID : ");
  my_put_nbr(getpid());
  my_putchar('\n');
}
