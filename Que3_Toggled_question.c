#include<unistd.h>
#include<stdio.h>

int lav[2];
void  parent_code()
{
    char *buffer1="PPPPP";                   
    char *buffer2="LLLLL";                   
    
    close(lav[0]);
    
    write(lav[1],buffer1,20);                        
    write(lav[1],buffer2,20);                        
    
    printf(" End Of The Parent\n");
}

void child_code()
{
    char buffer[100];
    int l,o;
    close(lav[1]);
    l = read(lav[0],buffer,100);                             
   
    printf(" Number Of Char Read : %d\n ",l);
    
    for(o = 0;o<l;o++)
    {
       printf("%c",buffer[o]);
    }
    
    printf(" End Of The Child\n");
}

int main()
{
    int var,o;
    pid_t p;
    var = pipe(lav);                                
    
    p = fork();                             
    if(p == 0)
    {
        child_code();
    }
    else
    {
        parent_code();
    }
    
    return 0;
} 