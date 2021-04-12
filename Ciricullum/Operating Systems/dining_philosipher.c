// #include<stdio.h>
// #include<stdlib.h>
// #include<pthread.h>
// #include<semaphore.h>
// #include<unistd.h>

// sem_t room;
// sem_t chopstick[5];

// void * philosopher(void *);
// void eat(int);
// int main()
// {
// 	int i,a[5];
// 	pthread_t tid[5];

// 	sem_init(&room,0,4);

// 	for(i=0;i<5;i++)
// 		sem_init(&chopstick[i],0,1);

// 	for(i=0;i<5;i++){
// 		a[i]=i;
// 		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
// 	}
// 	for(i=0;i<5;i++)
// 		pthread_join(tid[i],NULL);
// }

// void * philosopher(void * num)
// {
// 	int phil=*(int *)num;

// 	sem_wait(&room);
// 	printf("\nPhilosopher %d has entered room",phil);
// 	sem_wait(&chopstick[phil]);
// 	sem_wait(&chopstick[(phil+1)%5]);

// 	eat(phil);
// 	sleep(2);
// 	printf("\nPhilosopher %d has finished eating",phil);

// 	sem_post(&chopstick[(phil+1)%5]);
// 	sem_post(&chopstick[phil]);
// 	sem_post(&room);
// }

// void eat(int phil)
// {
// 	printf("\nPhilosopher %d is eating",phil);
// }

#include<stdio.h>

// #define n 5

int n;

int cP = 0,i;

struct fork{
	int taken;
}fA[10];

struct pp{
	int left;
	int right;
}p_status[10];

void dinner(int pID){
	if(p_status[pID].left==10 && p_status[pID].right==10)
        printf("Philosopher %d completes dinner\n",pID+1);
	else if(p_status[pID].left==1 && p_status[pID].right==1){
            printf("Philosopher %d completes dinner\n",pID+1);

            p_status[pID].left = p_status[pID].right = 10;
            int otherFork = pID-1;
            if(otherFork== -1)
                otherFork=(n-1);

            fA[pID].taken = fA[otherFork].taken = 0;
            printf("Philosopher %d releases fork %d and fork %d\n",pID+1,pID+1,otherFork+1);
            cP++;
        }
        else if(p_status[pID].left==1 && p_status[pID].right==0){
                if(pID==(n-1)){
                    if(fA[pID].taken==0){
                        fA[pID].taken = p_status[pID].right = 1;
                        printf("Fork %d taken by philosopher %d\n",pID+1,pID+1);
                    }else{
                        printf("Philosopher %d is waiting for fork %d\n",pID+1,pID+1);
                    }
                }else{
                    int dupphilID = pID;
                    pID-=1;

                    if(pID== -1)
                        pID=(n-1);

                    if(fA[pID].taken == 0){
                        fA[pID].taken = p_status[dupphilID].right = 1;
                        printf("Fork %d taken by Philosopher %d\n",pID+1,dupphilID+1);
                    }else{
                        printf("Philosopher %d is waiting for Fork %d\n",dupphilID+1,pID+1);
                    }
                }
            }
            else if(p_status[pID].left==0){ //nothing taken yet
                    if(pID==(n-1)){
                        if(fA[pID-1].taken==0){
                            fA[pID-1].taken = p_status[pID].left = 1;
                            printf("Fork %d taken by philosopher %d\n",pID,pID+1);
                        }else{
                            printf("Philosopher %d is waiting for fork %d\n",pID+1,pID);
                        }
                    }else{
                        if(fA[pID].taken == 0){
                            fA[pID].taken = p_status[pID].left = 1;
                            printf("Fork %d taken by Philosopher %d\n",pID+1,pID+1);
                        }else{
                            printf("Philosopher %d is waiting for Fork %d\n",pID+1,pID+1);
                        }
                    }
        }else{}
}

int main(){
    printf("Enter the number of philosopher: ");
    scanf("%d", &n);
	for(i=0;i<n;i++)
        fA[i].taken=p_status[i].left=p_status[i].right=0;
	while(cP<n){
		for(i=0;i<n;i++)
            dinner(i);
		printf("\nTill now num of philosophers completed dinner are %d\n\n",cP);
	}
	return 0;
}