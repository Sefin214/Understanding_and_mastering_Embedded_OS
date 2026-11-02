#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>


int main(){
	int stat = 0;
	const char *fifo_path = "my_own_pipe";
	stat = mkfifo(fifo_path, 0666);
	if(stat == -1){
		if(errno == EEXIST){
			printf("Named pipe already exists. \n");
		}
		else{
			perror("Failed to create a Named pipe");
			return -1;
		}
	}
	else{
		printf("Named pipe created successfully. \n");
	}

	return 0;
} 	
