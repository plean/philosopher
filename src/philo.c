/*
** philo.c for  in /home/melis_m/code/c/philo/src
**
** Made by Matteo MELIS
** Login   <melis_m@epitech.net>
**
** Started on  Sun Mar 26 20:06:13 2017 Matteo MELIS
** Last update Sun Mar 26 20:06:13 2017 Matteo MELIS
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo.h"
#include "extern.h"

int	eat(pthread_mutex_t *chopstick)
{
  if (pthread_mutex_lock(chopstick))
    return (1);
  lphilo_take_chopstick(chopstick);
  usleep(10);
  lphilo_eat();
  return (0);
}

int	rest(pthread_mutex_t *chopstick1, pthread_mutex_t *chopstick2)
{
  usleep(10);
  pthread_mutex_unlock(chopstick1);
  lphilo_release_chopstick(chopstick1);
  pthread_mutex_unlock(chopstick2);
  lphilo_release_chopstick(chopstick2);
  lphilo_sleep();
  return (0);
}

int	think(pthread_mutex_t *chopstick)
{
  if (pthread_mutex_lock(chopstick))
    return (1);
  lphilo_take_chopstick(chopstick);
  usleep(10);
  lphilo_think();
  return (0);
}
