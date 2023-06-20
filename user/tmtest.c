//Joshua Poblete
//Project 2
// 6/7/2023, Summer
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "stddef.h"

//User Level program, tmtest.c
//Simple user level program that utilizes the system call "timeins" created for project 2
int main(int argc, char *argv[])
{
int start, end, result; //Variables used to track time
 start = timeins();
 sleep(500); //it's 500 here, took too long when I inputted 1000. Will still work with 1000
 end = timeins(); 
 result = end - start;
 printf("Time in seconds: %d\n",result);  
 exit(0);
}