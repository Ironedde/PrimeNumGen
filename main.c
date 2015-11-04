#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//Included for threading
#include <pthread.h>

int curr_arr_size = 1024*1024;
int* primes;
int ind = 2;						//Array start


//Threads


//Sum of the digits in the number
int digit_sum(int n) {

  int r = 0;

  while(n != 0) {
    r += n % 10;
    n /= 10;
  }

  return r;
}

int is_prime(int prime) {
  int sr = (int)sqrt((double)prime);			//Where to stop
  if(digit_sum(prime) % 3 == 0) return 0;		//Sum dividable by 3?
  int j;			
  for(j = 0; j < ind+1; j++) {				//Go through the entire array of primes
   if(primes[j] > sr) break;				//Time to stop?
    if(prime % primes[j] == 0) return 0;		//Found factor
  }

  return 1;
}


int main(int argc, char** argv) {
 
  primes = malloc(curr_arr_size);
  primes[0] = 5;					//
  primes[1] = 7;					//Basic primes
  //The way to create threads
  //int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg)
  //int pthread_create(pthread_t *restrict tidp, NULL, void *(*start_rtn)(void), NULL);
  int i;
  char ch; 
  for(i = 9 ;; i += 2) {				//Every 2:nd
    if(is_prime(i)) {					//If prime
      if(ind+1 == curr_arr_size){
	   printf("Increasing array size");
   	   scanf("%c", &ch);
      	   primes = realloc(primes,curr_arr_size*2);    
      }
      primes[ind++] = i;				//Insert into array
      printf("Found prime: %d\n", i);			
    }
  }
}
