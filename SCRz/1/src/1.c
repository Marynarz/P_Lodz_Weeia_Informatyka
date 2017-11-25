#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

void* function( void* arg)
{
	sigset_t set;
	siginfo_t info;
	sigfillset(&set); //blokuje wszystkie synaly
	sigdelset(&set,SIGRTMIN); //przepuszcza konkretny sygnal

	printf("This is thread %d\n",pthread_self());

	while (1)
	{
		sigwaitinfo(&set, &info);
		printf("Odebrano!");
		break;
	}

	return 0;
}

void* function2( void* arg)
{
	for(int i=0; i<10;i++)
		printf("Count: %d\n",i);
	printf("This is thread %d\n",pthread_self());
	return 0;
}

int main(void) {
	pthread_t tid1, tid2;
	pthread_attr_t attr;
	sigset_t set;
	union sigval value;

	sigfillset(&set); //blokowanie sygnalow
	pthread_sigmask( SIG_BLOCK, &set, NULL);


	   pthread_create( &tid1, NULL, &function, NULL ); //utworzenie watku
	   //pthread_create( &tid2, NULL, &function2, NULL);

	   sleep(10);
	   sigqueue(getpid(),41,value);

	   pthread_join(tid1,NULL); //zablokowanie programu do czasu wykonania watku tid
	   //pthread_join(tid2,NULL);
	   return EXIT_SUCCESS;
}
