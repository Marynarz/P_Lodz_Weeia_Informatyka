	#include <stdio.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <pthread.h>
	#include <unistd.h>

	void*  function( void*  arg )
	{
		printf("Uruchomilem watek 1 \n ");
		while(1);

	   return( 0 );
	}

	void*  function2( void*  arg )
	{
		printf("uruchomilem watek 2 \n");
		while(1);

	   return( 0 );
	}



	int main( void )
	{
		union sigval value;
		pthread_t tid1, tid2;
		sigset_t set;

		pthread_create( &tid1,NULL, &function, NULL );
		pthread_create( &tid2,NULL, &function2, NULL );

		sigfillset(&set); //blokowanie sygnalow
		pthread_sigmask( SIG_BLOCK, &set, NULL);
		sigemptyse(&set);
		sigaddset(&set,SIGTMIN);



	   sigqueue(getpid(),41,value);
	   sleep(5);
	   printf("wyslalem sygnal \n ");

	   //pthread_join(tid1,NULL);
	   //pthread_join(tid2,NULL);

	   /* Allow threads to run for 60 seconds. */

	   return EXIT_SUCCESS;
	}


	// watek glowny a nastepnie dwa watki potomne

	//ptthread_self - identyfikator watku

	// bez slipa watek potomny zostanie zabity.
