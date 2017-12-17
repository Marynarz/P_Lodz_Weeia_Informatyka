#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

void* function( void* arg)
{
	unsigned int counter =0;
	sigset_t set;
	siginfo_t info;
	sigfillset(&set); //blokuje wszystkie synaly
	sigdelset(&set,SIGRTMIN); //przepuszcza konkretny sygnal

	pthread_sigmask(SIG_BLOCK,&set,NULL);

	printf("This is thread %d\n",pthread_self());

	sigemptyset(&set);
	sigaddset(&set,SIGRTMIN);

	while (1)
	{
		sigwaitinfo(&set, &info);
		printf("Odebrano! Sygnal w kolejnosci: %d, NR sygnalu: %d,z danymi: %d\n",++counter,info.si_code,info.__data.__proc.__pdata.__kill.__value.sival_int);
	}

	return 0;
}

void* function2( void* arg)
{
	unsigned int counter =0;
	sigset_t set;
	siginfo_t info;
	sigfillset(&set); //blokuje wszystkie synaly
	sigdelset(&set,42); //przepuszcza konkretny sygnal

	pthread_sigmask(SIG_BLOCK,&set,NULL);

	printf("This is thread %d\n",pthread_self());

	sigemptyset(&set);
	sigaddset(&set,42);

	while (1)
	{
		sigwaitinfo(&set, &info); /// set to numer sygnalu, info
		printf("Odebrano! Sygnal w kolejnosci: %d, NR sygnalu: %d,z danymi: %d\n",++counter,info.si_code,info.__data.__proc.__pdata.__kill.__value.sival_int);
	}

	return 0;
}

int main(void) {
	pthread_t tid1, tid2;
	//pthread_attr_t attr;
	sigset_t set;

	union sigval value;
	value.sival_int=0;

	sigfillset(&set); //blokowanie sygnalow
	pthread_sigmask( SIG_BLOCK, &set, NULL);

	pthread_create( &tid1, NULL, &function, NULL ); //utworzenie watku
	pthread_create( &tid2, NULL, &function2, NULL);
	while(1)
	{
			sleep(5);
			value.sival_int+=10;
			sigqueue(getpid(),SIGRTMIN,value); //wysylanie sygnalu
	}


	pthread_join(tid1,NULL); //zablokowanie programu do czasu wykonania watku tid
	pthread_join(tid2,NULL);
	return EXIT_SUCCESS;
}
