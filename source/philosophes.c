/*
** philosophes.c for philosophes in /home/mathon_j/rendu/PSU_2014_philo/source
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Fri Feb 20 14:41:13 2015 Jérémy MATHON
** Last update Tue Feb 24 12:18:24 2015 Jérémy MATHON
*/

#include	"philosophes.h"

void		philo_eating(t_philo *t)
{
  g_chopsticks[t->id] = 1;
  g_chopsticks[(t->id + 1) % 7] = 1;
  printf("Le philosophe %d mange...\n", t->id);
  sleep(TIME_EAT);
  t->status = EATING;
  t->gook -= t->hunger;
  pthread_mutex_unlock(&g_mutex);
  if (t->gook < 0)
    t->gook = 0;
  printf("Le philosophe %d a mangé %d grains de riz.\n", t->id, t->hunger);
  printf("Il reste %d dans le bol du philosophe %d.\n", t->gook, t->id);
  pthread_mutex_lock(&g_mutex);
  g_chopsticks[t->id] = 0;
  g_chopsticks[(t->id + 1) % 7] = 0;
  pthread_mutex_unlock(&g_mutex);
}

void		philo_thinking(t_philo *t)
{
  t->status = THINKING;
  g_chopsticks[t->id] = 1;
  pthread_mutex_unlock(&g_mutex);
  printf("Le philosophe %d pense...\n", t->id);
  sleep(TIME_THINK);
  printf("Le philosophe %d arrête de penser.\n", t->id);
  while (t->status != EATING)
    {
      pthread_mutex_lock(&g_mutex);
      if (g_chopsticks[(t->id + 1) % 7] == 0)
	philo_eating(t);
      else
	pthread_mutex_unlock(&g_mutex);
    }
}

void		philo_sleeping(t_philo *t)
{
  pthread_mutex_unlock(&g_mutex);
  if (t->status == SLEEPING)
    return ;
  printf("Le philosophe %d se repose.\n", t->id);
  t->status = SLEEPING;
  sleep(TIME_SLEEP);
  printf("Le philosophe %d est en pleine forme !!\n", t->id);
}

void		*handler_table_philo(void *arg)
{
  t_philo	*t;
  int		left_chopsticks;
  int		right_chopsticks;

  t = (t_philo *)arg;
  printf("Le philosophe %d rejoint la table des philosophes.\n", t->id);
  while (t->gook > 0)
    {
      pthread_mutex_lock(&g_mutex);
      left_chopsticks = g_chopsticks[t->id];
      right_chopsticks = g_chopsticks[(t->id + 1) % 7];
      if (left_chopsticks == 0 && right_chopsticks == 0 && t->status != EATING)
	philo_eating(t);
      else if (left_chopsticks == 0 &&
	       t->status != EATING && t->status != THINKING)
	philo_thinking(t);
      else
	philo_sleeping(t);
    }
  printf("Le philosophe %d quitte la table !\n", t->id);
  return (NULL);
}
