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
	printf("Message Queue ID is: %d\n", ID );

	
	msgctl(ID, IPC_STAT, NULL);                         
	
    printf(" Contents From The Structure Are : \n ");
	printf("Number Of Messages In The Queue : %d\n ",mybuff.msg_qnum);
	printf("Number Of Bytes In The Queue : %d\n ",mybuff.msg_cbytes);
	printf("Maximum Number Of Bytes In The Queue : %d\n ",mybuff.msg_qbytes);

	
	msgrcv(ID, &p1, sizeof(p1), 5, 0);                     
	printf("Type 1  Is : %ld\n",p1.mytype);
	printf("1st Message Is : %s\n",p1.data);

	msgrcv(ID, &p2, sizeof(p2), 7, 0);                    
	printf("Type 2 Is : %ld\n",p2.mytype);
	printf("2nd Message Is : %s\n",p2.data);
	
    msgctl(ID, IPC_RMID, NULL);                           
	return 0;
}