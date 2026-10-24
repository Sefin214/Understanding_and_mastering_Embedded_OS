#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
	int i;
	for(i=0; envp[i]!=NULL; i++)
		puts(envp[i]);
	printf("\n");
	
	printf("HOME: %s\n", getenv("HOME"));
	return 0;
}

