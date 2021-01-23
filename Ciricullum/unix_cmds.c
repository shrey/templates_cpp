#include<stdio.h>
#include<unistd.h>


int main(){
    int cur_id, par_id;
    cur_id = getpid();
    par_id = getppid();
    printf("Process Id: %d\n",cur_id);
    printf("Parent Process Id: %d\n",par_id);
    return 0;
}