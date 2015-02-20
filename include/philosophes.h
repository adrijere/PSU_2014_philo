/*
** philosophes.h for philosophes in /home/mathon_j/rendu/PSU_2014_philo/include
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Mon Feb 16 13:23:56 2015 Jérémy MATHON
** Last update Fri Feb 20 14:16:11 2015 Valentin Cardon
*/

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

# include	<pthread.h>

# define	NB_PHILO	7
# define	GOOK_SIZE	100
# define	TIME_EAT	50
# define	TIME_THINK	50

enum		e_status
  {
    EATING = 0,
    THINKING,
    SLEEPING
  };

typedef struct	s_philo
{
  int		numb_philo;
  e_status     	status;
  int		gook;
}		t_philo;

#endif /* !PHILOSOPHES_H_ */
