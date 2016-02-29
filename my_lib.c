/*
** my_lib.c for my_lib in /home/costa_b/rendu/PSU_2013_minitalk/src_server
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Mon Mar 17 14:04:26 2014 Kevin Costa
** Last update Tue Mar 18 12:10:46 2014 Kevin Costa
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"

void		my_putchar(char c)
{
  write (1, &c, 1);
}

int		my_putstr(char *str)
{
  if (str == NULL)
    {
      my_putstr("Error Argument");
      return (1);
    }
  while (*str)
    my_putchar(*str++);
  return (0);
}

int		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
  return (0);
}

int		overflow(char *str, char *ref)
{
  int		a;
  int		lenght;
  int		lenght_2;

  lenght = my_strlen(str);
  lenght_2 = my_strlen(ref);
  a = 0;
  if (lenght > lenght_2)
    return (-1);
  if (lenght < lenght_2)
    return (0);
  while (str[a])
    {
      if (str[a] == ref[a])
        a++;
      if (str[a] > ref[a])
        return (-1);
      if (str[a] < ref[a])
        return (0);
    }
  return (0);
}

int		my_getnbr(char *str)
{
  int		result;
  int		power;

  if (str == NULL)
    return (-1);
  result = 0;
  power = 1;
  while (('-' == (*str)) || ((*str) == '+'))
    {
      if (*str == '-')
        power = -power;
      str++;
    }
  while ((*str >= '0') && (*str <= '9'))
    {
      result = (result * 10) + ((*str) - '0');
      str++;
    }
  return (result * power);
}
