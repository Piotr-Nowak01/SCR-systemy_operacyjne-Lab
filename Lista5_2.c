#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define buf_size 256
int main(int argc, char *argv[])
{
	pid_t pid; 
	int fd[2], in_fd,n;
	char buf[buf_size];
	if ( pipe(fd) < 0 ) //sprawdzanie czy stworzono pipe'a
		{
			fprintf(stderr, "Blad\n");
			return 1;
		}
	pid=fork(); //tworzenie dziecka
	if(pid==0) //dziecko
	{	
		close(fd[1]);  //zamkniecie zapisu
		close(0);
		dup(fd[0]);
		close(fd[0]);
		execlp("display","display","-",NULL); 	//wyswietlanie na ekranie obrazka
	}
	else if( pid>0) //rodzic
	{
		close(fd[0]);  //zamkniecie odczytu
		if ((in_fd=open(argv[1], O_RDONLY))<0)  // jesli podczas otwierania plikow wystapil blad
		{
			fprintf(stderr, "Blad\n");
			return 2;
		}
		while ((n=read(in_fd, &buf, buf_size))>0) //wczytywanie danych
		{
			if (write(fd[1], &buf, n)<0) //jesli podczas zapisywania wystapil blad
			{
				fprintf(stderr, "Blad\n");
				return 3;
			}		
		} 
		sleep(1);
		close(fd[1]);
		close(in_fd);
	}
	else 	//blad
	{
		fprintf(stderr, "Blad\n");
		return 4;
	}
}
