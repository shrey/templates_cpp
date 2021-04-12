#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t r;
sem_t frk[5];

void eat(int);

void * philosopher(void * num)
{
	int ph=*(int *)num;

	sem_wait(&r);
	printf("\nPhilosopher %d enters ",ph);
	sem_wait(&frk[ph]);
	sem_wait(&frk[(ph+1)%5]);

	eat(ph);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",ph);

	sem_post(&frk[(ph+1)%5]);
	sem_post(&frk[ph]);
	sem_post(&r);
}

void eat(int ph)
{
	printf("\nPhilosopher %d eating" ,ph);
}

int main()
{
	int i,a[5];
	pthread_t tid[5];

	sem_init(&r,0,4);

	for(i=0;i<5;i++)
		sem_init(&frk[i],0,1);

	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}
