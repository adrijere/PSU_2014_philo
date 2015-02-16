/*
** philosophes.h for philosophes in /home/mathon_j/rendu/PSU_2014_philo/include
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Mon Feb 16 13:23:56 2015 Jérémy MATHON
** Last update Mon Feb 16 13:41:12 2015 Jérémy MATHON
*/

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

# define	NB_PHILO	7

# define	GOOK_SIZE	100

enum		e_status
  {
    EATING,
    THINKING,
    SLEEPING
  };

typedef		s_philo
{
  int		philo;
  e_status     	status;
  int		gook;
}		t_philo;

#endif /* !PHILOSOPHES_H_ */
