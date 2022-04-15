#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

#define key 33

struct messagequee
{
	long mytype;
	char data[512];
};

int main()
{
	int ID;
	struct messagequee p1, p2;
	struct msqid_ds mybuff;

	ID = msgget(key, IPC_CREAT|0644);              
	
        if(ID < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Message Queue Id: %d\n",ID);

	
	p1.mytype = 5;
	strcpy(p1.data, "Message In The Queue Transmitter");

	p2.mytype = 7;
	strcpy(p2.data, "Transmitting The Message");

	msgsnd(ID, &p1, strlen(p1.data)+1, 0);
	perror("msgsnd1");

	msgsnd(ID, &p2, strlen(p2.data)+1, 0);
	perror("msgsnd2");
 
	
	msgctl(ID, IPC_STAT, NULL);

	
    printf(" Contents From The Structure Are : \n");
	printf(" Number Of Message In Queue : %d\n",mybuff.msg_qnum);
	printf(" Number Of Bytes In Queue : %d\n",mybuff.msg_cbytes);
	printf(" Maximum Number Of Bytes In Queue : %d\n",mybuff.msg_qbytes);

	return 0;
}