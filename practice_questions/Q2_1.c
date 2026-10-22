#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	struct rusage start, end;

	printf("Device running specs are \n");
	printf("-------------------------\n");

	getrusage(RUSAGE_SELF, &start);
	for(int i = 0; i < 1000000; i++){
	}
	getrusage(RUSAGE_SELF, &end);
	printf("User Mode Time : %ld microseconds\n", end.ru_utime.tv_usec - start.ru_utime.tv_usec);
	
	
	getrusage(RUSAGE_SELF, &start);
	for(int i = 0; i < 1000000; i++){
		getpid();
	}
	getrusage(RUSAGE_SELF, &end);
	printf("Kernel Mode Time : %ld microseconds\n", end.ru_utime.tv_usec - start.ru_utime.tv_usec);
	
	return 0;
}
