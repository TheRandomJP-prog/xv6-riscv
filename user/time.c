//Joshua Poblete
//Project 2
// 6/7/2023, Summer
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "stddef.h"

//User Level program, time.c

int main(int argc, char *argv[])  
{
  if(argc < 2) //If nothing was inserted into input
  {
    printf("No arguement inputted, 0 secs \n");
    exit(0);
  }
  
  int TimeStart = uptime(); //Start of time.c program
  //printf("TimeStart is equal to = %d.\n", TimeStart); //Debugging line, check for time variables from uptime
  int checkPID = fork(); //Fork procceses into parent and child, checkPID is used to check status of child process

  if(checkPID < 0) //If fork fails
  {
    printf("Fork Failed");
    exit(0); // No time reported since fork failed
  } 
  if(checkPID == 0) //If fork is successful
  {
    exec(argv[1], argv+1);
    //printf("child proccess success"); //Debuggin Line, just to see if fork actually worked
    exit(0);
  }

wait(NULL); //Wait for child process to end

int timeEnd = uptime(); //Takes the time after child proccess finished
//printf(" timeEnd is equal to = %d.\n", timeEnd); //Debugging line, check for time variables from uptime
int seconds = (timeEnd - TimeStart);

printf("%s ran in %d ticks in Real-time.\n", argv[1], seconds);

exit(0);
}