#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char* argv[]) {

	int pid = atoi(argv[2]);
	int signal=atoi(argv[1]);
	union sigval value;

	value.sival_int = atoi(argv[3]);

	sigqueue(pid,SIGRTMIN,value); //wysylanie sygnalu

	return EXIT_SUCCESS;
}
