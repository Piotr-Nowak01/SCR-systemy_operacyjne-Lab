#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
void blad(const char* wiadomosc)
{
	fprintf(stderr, "%s \n", wiadomosc);
	exit -1;
}
int main()
{
	int fd_file, fd_area;
	char *adres, buff[1];
	struct stat status;
	int zlicz, znaki;
	char nazwa [100];
	int i=0;
	if ((fd_area=open("pamiec.txt",O_RDWR))<0)
	{
		blad("Blad podczas otwierania pliku uzywanego do mapowania pamieci");
	}
	while (1)
	{
		zlicz=lseek(fd_area,0,SEEK_END);
		printf("Podaj nazwe pliku \n");
		printf("Jesli chcesz skonczyc dzialanie programu, wpisz '.' \n");
		scanf("%s",nazwa);
		if (nazwa[0]=='.')
		{
			return 0;
		}
		if ((fd_file=open(nazwa,O_RDONLY))<0)
		{
			blad("Nie udalo sie odczytac pliku.\n");
		}
		if (fstat(fd_file,&status)==-1)
		{
			blad("Blad przy pozyskiwaniu statystyk pliku");
		}
		adres=mmap(NULL, status.st_size+zlicz, PROT_WRITE | PROT_READ , MAP_SHARED, fd_area, 0);
		ftruncate(fd_area,status.st_size+zlicz);
		if(adres==MAP_FAILED)
		{
			blad("Blad przy mapowaniu pliku");
		}
		i=0;
		while((znaki=read(fd_file,buff,1))>0)
		{
			adres[zlicz+i]=buff[0];
			i++;
		}
	}
}
