/*
** philo.h for  in /home/melis_m/code/c/philo/include
**
** Made by Matteo MELIS
** Login   <melis_m@epitech.net>
**
** Started on  Sun Mar 26 20:06:01 2017 Matteo MELIS
** Last update Sun Mar 26 20:06:01 2017 Matteo MELIS
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>

typedef enum	e_tristate
{
  UNKNOWN = -1,
  THINK = 0,
  EAT = 1,
  REST = 2,
}		t_tristate;

typedef enum	e_position
{
  BEGIN = -1,
  ELSE = 0,
  END = 1,
}		t_position;

typedef struct		s_philo
{
  pthread_mutex_t	chopstick;
  pthread_t		philosophe;
  t_tristate		state;
  int			eat;
  int			nb;
  t_position		pos;
}			t_philo;

int	eat(pthread_mutex_t *);
int	rest(pthread_mutex_t *, pthread_mutex_t *);
int	think(pthread_mutex_t *);

#endif /* !PHILO_H_ */
