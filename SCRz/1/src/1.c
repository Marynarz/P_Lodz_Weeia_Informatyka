#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* function( void* arg)
{
	printf("This is thread %d\n",pthread_self());
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

	   pthread_create( &tid1, NULL, &function, NULL );
	   pthread_create( &tid2, NULL, &function2, NULL);

	   pthread_join(tid1,NULL);
	   pthread_join(tid2,NULL);
	   return EXIT_SUCCESS;
}
