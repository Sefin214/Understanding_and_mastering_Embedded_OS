#include <stdio.h>
#include <pthread.h>

void* t_child(void *){
	printf("Hello from thread child\n");
}

int main(){
	pthread_t t;	//Creating thread_t variable to create thread process.	
	pthread_create(&t, NULL, t_child, NULL);	//creation of thread.
	printf("Hello from Main \n");	//displaying from main.
	pthread_join(t, NULL);		//Waiting for thread process to complete.
	return(0);
}
