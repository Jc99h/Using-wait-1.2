#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "maxrand.h"

int main(int argc, char *argv[])
{
  int aleatorio=maxrand(100);
  int rc=fork();
  int status;
  int rc_wait=wait(&status);

  if(rc==0)
  {
    printf("Soy el hijo (pid:%d)\n", getpid());
    printf("Y el hijo retorna un numero aleatorio: %i\n", aleatorio);
    return aleatorio;
  }
  else
  {
    printf("Soy el padre de %d (pid:%d)\n", rc, getpid());
    if(WIFEXITED(status)!=0) //es distinto de cero si el hijo termino normalmente
    {
      printf("Soy el padre y obtengo el valor de salida el proceso hijo: %i\n", WEXITSTATUS(status));
    }
    return WEXITSTATUS(status);
  }
}