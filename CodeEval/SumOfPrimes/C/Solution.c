/* Author: Luigi Vincent
* Calculating the sume of the first 1000 primes
*/

#include <stdio.h>

int main() {
	unsigned long sum_of_primes = 0;
	int primes_needed = 1000;
	int sieve_size = 20 * primes_needed;
	int sieve[sieve_size];
	
	for (int i = 0; i < sieve_size; i++) {
		sieve[i] = 1;
	}

	for (int prime = 2; primes_needed > 0; prime++) {
		if (sieve[prime]) {
			sum_of_primes += prime;
			primes_needed--;

			for (int composite = prime + prime; composite < sieve_size; composite += prime) {
				sieve[composite] = 0;
			}
		}
	}

	printf("%d\n", sum_of_primes);
}