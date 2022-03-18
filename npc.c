//play games for user1
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAXSIZE 512
typedef struct user1Msg{
	long int msg_type;
	int select;
}user1Msg;

//define scissors = 1, stone = 2, cloth = 3
int main(void)
{
	//define some values
	user1Msg player1;
	int msg_id;
	
	msg_id = msgget((key_t)22, 0666|IPC_CREAT);
	if(msg_id == -1)
	{
		fprintf(stderr, "(for player1)msgget failed with error: %d\n", errno);
    exit(EXIT_FAILURE);
	}

	int i;
	srand(time(0));
	for(i=1;i<=10;i++)
	{
		player1.msg_type = 1;
		player1.select = rand()%3 + 1;
		if(msgsnd(msg_id, (void*)&player1, MAXSIZE, 0) ==-1)
		{
			fprintf(stderr, "msgsnd failed\n");
      exit(EXIT_FAILURE);
		}
	}
	printf("OK\n");
	exit(EXIT_SUCCESS);
}
