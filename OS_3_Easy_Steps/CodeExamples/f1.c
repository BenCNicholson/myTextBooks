 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
#include <string.h>
 
 int main(int argc, char *argv[]) {
 	printf("hello world (pid:%d)\n", (int) getpid());
 	int x = 100;
 	char msg[] = "hello";
 	int fd = open("./fork.c",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
 	int rc = fork();
 if (rc < 0) {
 // fork failed
 	fprintf(stderr, "fork failed\n");
 	exit(1);
 } else if (rc == 0) {
 // child (new process) 
 	printf("hello, I am child (pid:%d)\n And my fd value is %d",(int) getpid(), fd);
 } else {	
 // parent goes down this path (main)
	 //printf("hello, I am parent of %d (pid:%d) & my fd value is %d\n", rc, (int) getpid(),fd);
 	char *myargs[3];
	myargs[0] = strdup("echo");
	myargs[1] = strdup("Goodbye");
	myargs[2] = NULL;
	execvp(myargs[0],myargs);
 }
 return 0;
 }
