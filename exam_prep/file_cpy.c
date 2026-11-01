#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//Usage Function
void usage(){
	printf("Wrong Usage : ./<executable_file> <Source_filename> <Destination_filename> \n");
	exit(EXIT_FAILURE);
}
	
//Logic function
void copydata(int src_fd, int dest_fd){
	char buffer[1024];
	int bytes_read, bytes_written;
	
	while((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0 ){
		bytes_written = write(dest_fd, buffer, bytes_read);
		if(bytes_written<0){
			perror("Write Error\n");
			return;
		}
	}
	printf("File contents copied successfully\n");
}

//Main function
int main(int argc, char * argv[]){
	//arguments handler
	if(argc != 3)
		usage();
	
	//Opening source file
	int src_fd = open(argv[1], O_RDONLY);
	if(src_fd<0){
		perror("Cannot open the Source File\n");
		close(src_fd);
		return -1;
	}	

	//Opening destination file
	int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(dest_fd<0){
		perror("Cannot open the Destination File\n");
		close(src_fd);
		return -1;
	}	
	
	copydata(src_fd, dest_fd);
	close(src_fd);
	close(dest_fd);
	return(0);
}
	
