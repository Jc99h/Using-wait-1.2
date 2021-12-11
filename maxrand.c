#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int maxrand(int max)
{
  srand(time(0));
  return rand()%max;
}