/*
** philosophes.h for philosophes in /home/mathon_j/rendu/PSU_2014_philo/include
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Mon Feb 16 13:23:56 2015 Jérémy MATHON
** Last update Sun Feb 22 10:58:19 2015 Jérémy MATHON
*/

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

# include	<time.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<pthread.h>
# include	<unistd.h>

# define	NB_PHILO	7
# define	GOOK_SIZE	100
# define	TIME_EAT	5
# define	TIME_THINK	10
# define	TIME_SLEEP	15

enum		e_status
  {
    EATING = 0,
    THINKING,
    SLEEPING
  };

typedef struct		s_philo
{
  int			id;
  enum e_status     	status;
  int			gook;
  pthread_t		handler;
  int			hunger;
}			t_philo;

extern	t_philo	g_philo[NB_PHILO];

extern	pthread_mutex_t	g_mutex;

extern	int	g_chopsticks[NB_PHILO];

void		init_ressources();
void		philo_eating(t_philo *);
void		philo_thinking(t_philo *);
void		philo_sleeping(t_philo *);
void		*handler_table_philo(void *);
void		waiting_chopsticks();
int		verif_define();

#endif /* !PHILOSOPHES_H_ */
