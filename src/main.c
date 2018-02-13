/*
** main.c for  in /home/melis_m/code/c/philo/src
**
** Made by Matteo MELIS
** Login   <melis_m@epitech.net>
**
** Started on  Sun Mar 26 20:05:37 2017 Matteo MELIS
** Last update Sun Mar 26 20:05:37 2017 Matteo MELIS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "philo.h"
#include "extern.h"

static void	parse_args(int argc, char **argv,
			   int *philo_nb, int *max_eat)
{
  int		i;

  i = 1;
  *philo_nb = 0;
  *max_eat = 0;
  while (i < argc)
    {
      if ((strcmp(argv[i], "-e")) == 0)
	*max_eat = argv[i + 1] ? atoi(argv[++i]) : -1;
      else if ((strcmp(argv[i], "-p")) == 0)
	*philo_nb = argv[i + 1] ? atoi(argv[++i]) : -1;
      i += 1;
    }
}

static void	*thread_start(void *a)
{
  t_philo	*philosophe;
  int		ret;

  philosophe = a;
  while (philosophe->eat)
    {
      if (philosophe->pos == END)
	ret = think(&philosophe[-philosophe->nb].chopstick) ||
	  eat(&philosophe->chopstick) ||
	  rest(&philosophe->chopstick, &philosophe[-philosophe->nb].chopstick);
      else
	ret = think(&philosophe->chopstick) ||
	  eat(&philosophe[1].chopstick) ||
	  rest(&philosophe->chopstick, &philosophe[1].chopstick);
      philosophe->eat--;
      if (ret)
	return (NULL);
    }
  return (NULL);
}

static int	init_philosophes(int max_eat, int phil_nb,
				 t_philo *philosophes)
{
  int		i;
  void		*res;

  i = -1;
  while (++i < phil_nb)
    {
      philosophes[i].eat = max_eat;
      philosophes[i].pos = (!i || i == phil_nb - 1) * (!i * -2 + 1);
      philosophes[i].nb = i;
      pthread_mutex_init(&philosophes[i].chopstick, NULL);
      pthread_create(&philosophes[i].philosophe, NULL,
		     &thread_start, &philosophes[i]);
    }
  i = -1;
  while (++i < phil_nb)
    pthread_join(philosophes[i].philosophe, &res);
  return (0);
}

static int	philo(int argc, char **argv)
{
  t_philo	*philosophes;
  int		phil_nb;
  int		max_eat;

  parse_args(argc, argv, &phil_nb, &max_eat);
  if (!(phil_nb > 1 && max_eat >= 1))
    return (1);
  philosophes = calloc(sizeof(t_philo), phil_nb);
  if (!philosophes)
    return (1);
  init_philosophes(max_eat, phil_nb, philosophes);
  return (0);
}

int		main(int argc, char **argv)
{
  int		ret;

  RCFStartup(argc, argv);
  ret = philo(argc, argv);
  RCFCleanup();
  return (ret);
}
