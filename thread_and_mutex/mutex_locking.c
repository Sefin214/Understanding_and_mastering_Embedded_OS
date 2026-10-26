#include <stdio.h>
#include <pthread.h>

long long count = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* gfun(void *){
	int i = 0;
	for(i=0;i<1000000;i++){
		pthread_mutex_lock(&m);	
		count+=1;
		pthread_mutex_unlock(&m);	
	}
	return NULL;
}

int main(){
	pthread_t t1,t2;
	pthread_create(&t1, NULL, gfun, NULL);
	pthread_create(&t2, NULL, gfun, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Counter: %lld\n",count);
	return 0;
}
