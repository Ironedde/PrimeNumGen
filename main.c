#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int primes[8096];
int ind = 2;

int digit_sum(int n) {

  int r = 0;

  while(n != 0) {
    r += n % 10;
    n /= 10;
  }

  return r;
}

int is_prime(int prime) {
  int sr = (int)sqrt((double)prime);
  if(digit_sum(prime) % 3 == 0) return 0;
  int j;
  for(j = 0; j < ind+1; j++) {
   if(primes[j] > sr) break;
    if(prime % primes[j] == 0) return 0;
  }

  return 1;
}


int main(int argc, char** argv) {
  primes[0] = 5;
  primes[1] = 7;

  int i;
  for(i = 9 ;; i += 2) {
    if(is_prime(i)) {
      primes[ind++] = i;
      printf("Found prime: %d\n", i);
    }
  }
}
