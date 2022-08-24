#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  printf("hello world (pid:%d)\n", (int)getpid());
  fflush(stdout);
  int val = 100;
  int rc = fork();
  if (rc < 0) {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0){
    // child (new process)
    sleep(1);
    val = 101;
    printf("hello, I am child (pid:%d). I have %d\n", (int)getpid(), val);
  }
  else{
    // parent goes down this path (main)
    val = 102;
    int wc = wait(NULL);
    assert(wc >= 0);
    // Notice that child process has a copy of val and it is not changing val
    // of parent.
    printf("hello, I am parent of %d (pid:%d). I have %d\n", rc, (int)getpid(), val);
  }
  return 0;
  
}
