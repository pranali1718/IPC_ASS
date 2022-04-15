
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>

#define key 33

int main()
{
    char *p;
    int ID;
    
    ID = shmget(key,250,IPC_CREAT|0644);              
    
    if(ID < 0)
    {
        perror("shmget\n");
        return 0;
    }
    
    printf(" ID is = %d\n ", ID );
    
    
    p = shmat(ID,0,0);                      
    
    printf("Address : %p\n", p );
    printf("Data : %s\n", p ); 
    
    
    return 0;
} 