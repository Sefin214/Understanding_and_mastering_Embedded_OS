#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main(){
	int client_fd = socket(AF_INET, SOCK_STREAM, 0);
	int client_fd2 = socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd < 0){
		perror("Socket creation Failed!");
		return -1;
	}
	
	printf("TCP socket Successfully created. Descriptor ID: %d\n", client_fd);
	printf("TCP socket Successfully created. Descriptor ID: %d\n", client_fd2);
	getchar();
	close(client_fd);
	close(client_fd2);
	return 0;
}
