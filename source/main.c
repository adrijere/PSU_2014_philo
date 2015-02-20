/*
** main.c for philo in /home/cardon_v/Documents/PSU/PSU_2014_philo/source
**
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
**
** Started on  Fri Feb 20 14:11:40 2015 Valentin Cardon
** Last update Fri Feb 20 14:56:07 2015 Jérémy MATHON
*/

#include	<stdio.h>
#include	"philosophes.h"

t_philo		g_philo[NB_PHILO];

int		main()
{
  printf("Salut les Philo, bon app'\n");
  init_ressources();
  return (0);
}
