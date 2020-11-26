#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define buf_size 256
int main(int argc, char *argv[])
{
	pid_t pid;
	int fd[2], in_fd,n;
	char buf[buf_size];
	if ( pipe(fd) < 0 )
		{
			fprintf(stderr, "Blad\n");
			return 1;
		}
	pid=fork();
	if(pid==0) //dziecko
	{	
		close(fd[1]);
		close(0);
		dup(fd[0]);
		close(fd[0]);
		execlp("display","display","-",NULL);
	}
	else if( pid>0) //rodzic
	{
		close(fd[0]);
		if ((in_fd=open(argv[1], O_RDONLY))<0)
		{
			fprintf(stderr, "Blad\n");
			return 2;
		}
		while ((n=read(in_fd, &buf, buf_size))>0)
		{
			if (write(fd[1], &buf, n)<0)
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