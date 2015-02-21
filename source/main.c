/*
** main.c for philo in /home/cardon_v/Documents/PSU/PSU_2014_philo/source
**
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
**
** Started on  Fri Feb 20 14:11:40 2015 Valentin Cardon
** Last update Sat Feb 21 17:03:03 2015 Jérémy MATHON
*/

#include	<stdio.h>
#include	"philosophes.h"

t_philo		g_philo[NB_PHILO];
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;
int		g_chopsticks[NB_PHILO];

int		main()
{
  printf("Salut les Philo, bon app'\n");
  srand(time(NULL));
  init_ressources();
  waiting_chopsticks();
  return (0);
}
