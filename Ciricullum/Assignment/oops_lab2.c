#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int cur_id, par_id;
    cur_id = getpid();
    par_id = getppid();
    printf("Process Id: %d\n",cur_id);
    printf("Parent Process Id: %d\n",par_id);
    for(int i=0;i<5;i++)
    {
        if(fork() == 0)
        {
            printf("Son process id %d from Parent process id %d\n",getpid(),getppid());
            exit(0);
            // return 0;
        }
    }
    for(int i=0;i<5;i++)
        wait(NULL);
    par_id = getppid();
    printf("Parent id: %d\n", par_id);

}