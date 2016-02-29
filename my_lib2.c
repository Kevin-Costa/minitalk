/*
** my_lib2.c for my_lib2 in /home/costa_b/rendu/PSU_2013_minitalk/src_server
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Mar 17 14:04:42 2014 Kevin Costa
** Last update Fri Mar 21 15:16:02 2014 Kevin Costa
*/

#include	<stdlib.h>
#include	"lib.h"

int		my_strlen(char *str)
{
  int		a;

  a = 0;
  while (str[a])
    a++;
  return (a);
}

int		my_putstr2(char *str, char *str2)
{
  while (*str)
    my_putchar(*str++);
  while (*str2)
    my_putchar(*str2++);
  return (0);
}

int		my_puterror(char *str)
{
  while (*str)
    my_putchar(*str++);
  exit(1);
}
