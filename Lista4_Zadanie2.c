#include <stdio.h>
#include <time.h>
#include <signal.h>
void s1 (int signum) // wylaczenie programu
{
	printf("Sygnal zlapany o nr %d\n", signum);
	exit(0);
}
void s2 (int signum) // wyswietlenie komunikatu i powrot do pracy
{
	printf("Sygnal zlapany o nr %d\n", signum);
}
void s3 (int signum) // wstrzymanie na x iteracji
{

}
void s4 (int signum) // zignorowanie sygnalu
{
	;
}
int main(){
	int i=0;
	int milis=100;
	struct timespace req;
	req.tv_sec=0;
	req.tv_nsec=milis*1000000L;
	signal (SIGUSR1,s1);
	signal (SIGTERM,)s2;
//	signal (SIGALRM,s3);
	signal (SIGUSR2,s4);
	while (1)
	{
		i++;
		nanosleep(&req,(struct timespec *)NULL);
	}
return 0;
}