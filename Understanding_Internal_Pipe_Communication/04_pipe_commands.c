// Source - https://stackoverflow.com/q/21923982
// Posted by ngwilliams, modified by community. See post 'Timeline' for change history
// Retrieved 2026-10-21, License - CC BY-SA 3.0

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"

int main(int argc, char** argv)
{
 int pipefd[2];
 int childpid,childpid2;
 char* cmd[3]={"ls",NULL,NULL};
 char* cmd2[3]={"grep",".c",NULL};
 pipe(pipefd);
 if(childpid=fork()){
   //parent
 }else{  
   //child
   //write
   close(pipefd[0]);
   dup2(pipefd[1],STDOUT_FILENO);
   execvp("ls", cmd);
 }
 if(childpid2=fork()){
 }
 else{
   close(pipefd[1]);
   dup2(pipefd[0],STDIN_FILENO);
   execvp("grep",cmd2);
 }
 close(pipefd[0]);
 close(pipefd[1]);
 return 0;
}

