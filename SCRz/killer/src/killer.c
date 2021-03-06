#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char** argv) {

	pid_t pid;

	int signal;
	union sigval value;

	pid=atoi(argv[1]);

	signal = atoi(argv[2]);
	value.sival_int =atoi(argv[3]);

	sigqueue(getpid(),SIGRTMIN,value);
	return EXIT_SUCCESS;
}
