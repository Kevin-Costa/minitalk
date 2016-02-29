/*
** main.c for main in /home/costa_b/rendu/PSU_2013_minitalk/src_server
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Tue Mar 18 11:18:24 2014 Kevin Costa
** Last update Tue Mar 18 15:56:14 2014 Kevin Costa
*/

#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <signal.h>
#include        <sys/types.h>
#include	"server.h"
#include	"lib.h"

int		main(int ac, char **av)
{
  (void)av;
  if (ac != 1)
    {
      my_putstr("You don't need to put any argument\n");
      exit(1);
    }
  server();
  while (42)
    pause();
}
