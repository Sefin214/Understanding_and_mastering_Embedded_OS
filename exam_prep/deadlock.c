#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mu_a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mu_b = PTHREAD_MUTEX_INITIALIZER;

void* task1(void* ){
	printf("Locking mutex A......\n");
	pthread_mutex_lock(&mu_a);
	printf("mutex locked successfully.\n");
	sleep(1);
	
	printf("Locking mutex B......\n");
	pthread_mutex_lock(&mu_b);
	printf("Thread 1 Saved without Deadlock");
	
	pthread_mutex_unlock(&mu_a);
	pthread_mutex_unlock(&mu_b);
	return 0;
}

void* task2(void* ){
	printf("Locking mutex B......\n");
	pthread_mutex_lock(&mu_b);
	printf("mutex locked successfully.\n");
	sleep(1);
	
	printf("Locking mutex A......\n");
	pthread_mutex_lock(&mu_a);
	printf("Thread 2 Saved without Deadlock");
	
	pthread_mutex_unlock(&mu_a);
	pthread_mutex_unlock(&mu_b);
	return 0;
}

int main(){
	pthread_t t1,t2;
	
	if(pthread_create(&t1, NULL, task1, NULL) != 0){
		printf("Error while creating thread 1, Exiting the program");
		return -1;	
	}

	if(pthread_create(&t2, NULL, task2, NULL) != 0){
		printf("Error while creating thread 2, Exiting the program");
		return -1;	
	}
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("All tasks are carried without any deadlock, Operation Successfull\n");
	return 0;
}
	
