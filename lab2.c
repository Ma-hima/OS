/* Question 1: File Writing Using Parent and Child Processes
Problem Statement:
Develop a C program that demonstrates process synchronisation and shared file access. The program
shall create a child process; both processes will then write unique identifiers to a common file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>

int main(){
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
   
if (fd < 0) {
    wait (NULL);
    char wait[]="This line...";
perror("File open failed");
exit(1);
}
pid_t pid = fork();
// Write Child logic
if(pid==0){
   char msg[]="This line is written by child process\n ";
   write(fd,msg,strlen(msg));
}

// Write parent logic--------------

if(pid>0){
    // fork();
    char msg[]="This line is written by parent process\n ";
   write(fd,msg,strlen(msg));
}
return 0;
}