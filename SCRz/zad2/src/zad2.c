#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int randomizer()
{
	int i;
	int tab[1000];
	time_t tt;
	srand(time(&tt));
	for(i=0;i<1000;i++)
	{
		tab[i] = (rand()%500)-250;
	}
	return tab;
}
int main(void) {
	pid_t pid;
	pid_t wpid;
	int status;
	int channelId;
	int channelS;
	int fd;
	unsigned* addr;
	char rmsg[1000];

	if((channelId = ChannelCreate(NULL))==-1)
	{
		perror("ChannelCreate");
		return EXIT_FAILURE;
	}

	if((pid = fork())==-1)	//tworzenie rozdzialu na dwa procesy
	{
		perror("fork");
		return EXIT_FAILURE;
	}

	if(pid ==0)		//obsluga procesu potomnego
	{
		printf("Witam w kliencie!\n");
		fd = shm_open("liczby",O_RDWR|O_CREAT,0777);	//tworzenie obiektu pamieci dzielonej
		if(fd == -1)
		{
			fprintf(stderr,"Open failed: %s\n",strerror(errno));
			return EXIT_FAILURE;
		}

		if(ftruncate(fd,sizeof(*addr))==-1)
		{
			fprintf(stderr,"ftruncate: %s\n",strerror(errno));
		}
	    addr = mmap( 0, sizeof( *addr ),
	            PROT_READ | PROT_WRITE,
	            MAP_SHARED, fd, 0 );
	    if( addr == MAP_FAILED )
	    {
	        fprintf( stderr, "mmap failed: %s\n",
	            strerror( errno ) );
	        return EXIT_FAILURE;
	    }
	    printf( "Map addr is 0x%08x\n", addr );
	    //*addr = randomizer();
	    char msg[20] = "Polaczenie udane";
	    char rmsg[20] ="";
		int connection = ConnectAttach(0,getppid(),channelId,0,NULL); //tworzymy polaczenie

		printf("Polaczenie \n");
		int wiadomosc = MsgSend(connection,msg,20,rmsg,20);
		//sleep(30);
		printf("Rmsg: %s\n",rmsg);
		ConnectDetach(connection);		//koniec polaczenia
		close(fd);
		shm_unlink("liczby\n");	//usuwanie obiektu pamieci dzielonej
		return EXIT_SUCCESS;
	}
	else			//obsluyga procesu macierzystego
	{
		printf("Witam w hoscie!\n PID: %d\n",pid);
		char msg[20] = "";
		char rmsg[20] ="Reply Text Message";
		int odebrane = MsgReceive(channelId,msg,20,NULL);
		printf("Server: Text received: %s\n",msg);
		MsgReply(odebrane,0,rmsg,20);
	      do {
	        wpid = waitpid( pid, &status, 0 );
	      } while( WIFEXITED( status ) == 0 ); //oczekiwanie na zamkniecie klienta
	      //printf(status);
	      if((channelS = ChannelDestroy(channelId))==-1) //zamykamy kanal
	      {
	  		perror("ChannelDestroy");
	  		return EXIT_FAILURE;
	      }
	      return WEXITSTATUS( status );
	}
	return EXIT_SUCCESS;
}
