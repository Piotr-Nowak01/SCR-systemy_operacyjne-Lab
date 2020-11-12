#include <stdio.h>
#include <time.h>
int main(){
	int i=0;
	int milis=100;
	struct timespace req;
	req.tv_sec=0;
	req.tv_nsec=milis*1000000L;
	while (1)
	{
		i++;
		nanosleep(&req,(struct timespec *)NULL);
	}
}
/*
Bez opóźnienia powyższy program wyświetlał się na szczycie programu top. Po dodaniu opóźnienia w pętli, program przestał się wyświetlać na szczycie programu top.
Domyślną częstotliwość odświeżania programu top można zmienić za pomocą flagi -d x, gdzie x to czas, co jaki ma być odświeżany program top.
*/