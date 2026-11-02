#include <stdio.h>
#include <fnctl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define DEST_FILE output.txt

int main(int argc, char *argv[]){
	int fd = 0, bytes_written = -1;
	const char text[] = "Embedded Systems\n";
	
	//opening the file
	fd = open(DEST_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0766);
	if(fd < 0){
		printf("Error while creation of file\n");
		return -1;
	}
	
	//writing operartion
	bytes_written = write(fd, text, sizeof(text));
	if(bytes_written < 0){
		printf("Error occured while writing\n");
		return -1;
	}
	
	printf("Successfully wrote %d bytes. \n"

