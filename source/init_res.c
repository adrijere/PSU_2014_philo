/*
** init_res.c for init_res in /home/mathon_j/rendu/PSU_2014_philo/source
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Feb 20 14:14:10 2015 Jérémy MATHON
** Last update Fri Feb 20 14:57:51 2015 Jérémy MATHON
*/

#include	"philosophes.h"

void		init_ressources()
{
  int		i;

  i = 0;
  while (i < NB_PHILO)
    {
      printf("Le philosophe %d rejoint la table des philosophes avec un bol de riz de %d grains de riz.\n", i + 1, GOOK_SIZE);
      g_philo[i].numb_philo = i;
      g_philo[i].status = SLEEPING;
      g_philo[i].gook = GOOK_SIZE;
      i++;
    }
}
