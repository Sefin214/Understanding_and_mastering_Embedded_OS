#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){
	const char *fifo_name = "my_fifo";
	int result = mkfifo(fifo_name, 0766);
	if(-1 == result){
		if(errno == EEXIST){
			printf("Named pipe already exists\n");
			return -1;
		}	
		else{
			printf("Error occured while creating the pipe\n");
			return -1;
		}
	}
	else{
		printf("Named Pipe Created Successfully\n");
		return -1;
	}
	return 0;
}
