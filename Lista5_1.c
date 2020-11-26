#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define buf_size 256
int main(int argc, char *argv[])
{
	pid_t pid; 
	int fd[2], in_fd,n;
	char buf[buf_size];
	if ( pipe(fd) < 0 ) // sprawdzanie czy utworzono pipe'a
		{
			fprintf(stderr, "Blad\n");
			return 1;
		}
	pid=fork(); //tworzenie dziecka
	if(pid==0) //dziecko
	{	
		close(fd[1]);
		while (read(fd[0],&buf,1)>0) 	//wyswietlanie na terminalu
		{
			write(STDOUT_FILENO, "#", 1);
			write(STDOUT_FILENO, &buf, 1);
			write(STDOUT_FILENO, "#\n", 2);
		}
		close(fd[0]);	
	}
	else if( pid>0) //rodzic
	{
		close(fd[0]);
		if ((in_fd=open(argv[1], O_RDONLY))<0) 	 //jesli nie otwarto plikow to blad
		{
			fprintf(stderr, "Blad\n");
			return 2;
		}
		while ((n=read(in_fd, &buf, buf_size))>0) // gdy dane sa wczytywane
		{
			if (write(fd[1], &buf, n)<0) 		// jesli wystapil blad podczas zapisywania
			{
				fprintf(stderr, "Blad\n");
				return 3;
			}		
		} 
		close(in_fd);
	}
	else 	//blad
	{
		fprintf(stderr, "Blad\n");
		return 4;
	}
}
