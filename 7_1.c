#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define Liczba_watkow 10
void *wyswietl (void *id_watku)
{
	long idw=(long)id_watku;
	printf("Hello SCR. Written by thread %ld\n",idw);
	pthread_exit(NULL);
}
int main (){
pthread_t watki[Liczba_watkow];
for (long t=0; t<Liczba_watkow;t++)
	{
		printf("Tworzenie watku %ld \n",t);
		if (pthread_create(&watki[t], NULL, wyswietl, (void *)t))
		{
			printf("ERROR\n");
			exit(-1);
		}
	}
pthread_exit(NULL);
}
