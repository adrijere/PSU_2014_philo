/*
** init_res.c for init_res in /home/mathon_j/rendu/PSU_2014_philo/source
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Feb 20 14:14:10 2015 Jérémy MATHON
** Last update Sun Feb 22 09:55:07 2015 Jérémy MATHON
*/

#include	"philosophes.h"

void		init_ressources()
{
  int		i;

  i = 0;
  while (i < NB_PHILO)
    {
      g_philo[i].numb_philo = i + 1;
      g_philo[i].status = SLEEPING;
      g_philo[i].gook = GOOK_SIZE;
      g_philo[i].hunger = 20 + (rand() % 20);
      g_chopsticks[i] = 0;
      pthread_create(&(g_philo[i].handler), NULL, handler_table_philo, &g_philo[i]);
      i++;
    }
}

void		waiting_chopsticks()
{
  int		i;

  i = 0;
  while (i < 7)
    {
      pthread_join((g_philo[i].handler), NULL);
      i = i + 1;
    }
}

int		verif_define()
{
  if (NB_PHILO < 3)
    {
      printf("Erreur : le nombre de philosophes doit être supérieur à 3.\n");
      return (1);
    }
  else if (GOOK_SIZE < 0)
    {
      printf("Erreur : le nombre de grains de riz dans le bol doit être supérieur à 0.\n");
      return (1);
    }
  else if (TIME_EAT < 0 || TIME_THINK < 0 || TIME_SLEEP < 0)
    {
      printf("Erreur : l'un des timers d'activités est inférieur à 0.\n");
      return (1);
    }
  return (0);
}
