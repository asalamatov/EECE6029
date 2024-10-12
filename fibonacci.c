//##############################################
// TO RUN THIS CODE:
// 1) COMPILE (link the "pthread" library)
//    $ gcc fibonacci.c -lpthread
// 2) EXECUTE
//    $ ./a.out
// 3) FOLLOW THE PROMPT, ENTER A DIGIT INPUT
//###############################################


#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t child_thread;

int shared_nums_array[10000];
int top = -1;

void *soveFibonacci(void *vargp){
  int n1 = 0;
  int n2 = 1;
  int next = 0;

  int total_number = * (int*) vargp;

  printf("\nInside Thread:");

  for (int i = 0; i < total_number; i++){
    if (i<=1) 
      next = i;
    else {
      next = n1 + n2;
      n1 = n2;
      n2 = next;
    }
    
    shared_nums_array[i] = next;
  }
  
  pthread_exit(0);
}

int main(){
  // main() function is the Parent thread.
  int n;
  printf("Enter a number to get its fibonacci sequence: ");
  
  scanf("%d", &n);
  printf("\nBefore Thread!!!");
  pthread_create(&child_thread, NULL, soveFibonacci, (void*) &n);
  pthread_join(child_thread, NULL);
  printf("\nAfter Thread!!!");

  for (int i = 0; i < n; i++){
    printf("%d ", shared_nums_array[i]);
  }

  exit(0);
}
