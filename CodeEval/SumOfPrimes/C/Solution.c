/* Author: Luigi Vincent
* Calculating the sume of the first 1000 primes
*/

#include <stdio.h>

unsigned long compute_sum_of_primes(int primes_needed) {
	int sieve_size = 20 * primes_needed;
	int sieve[sieve_size];
	unsigned long sum = 0;

	for (int i = 0; i < sieve_size; i++) {
		sieve[i] = 1;
	}

	for (int prime = 2; primes_needed > 0; prime++) {
		if (sieve[prime]) {
			sum += prime;
			primes_needed--;

			for (int composite = prime + prime; composite < sieve_size; composite += prime) {
				sieve[composite] = 0;
			}
		}
	}

	return sum;
}

int main() {
	unsigned long sum_of_primes = compute_sum_of_primes(1000);
	printf("%lu\n", sum_of_primes);
}