/* Author: Luigi Vincent
* Calculating the sume of the first 1000 primes
*/

#include <stdio.h>


void initialize_array(int *array, int array_size, int value) {
	for (int i = 0; i < array_size; i++) {
		array[i] = value;
	}
}

unsigned long compute_sum_of_primes(int number_of_primes) {
	int sieve_size = 20 * number_of_primes;
	int sieve[sieve_size];
	unsigned long sum = 0;
	initialize_array(sieve, sieve_size, 1);

	for (int prime = 2; number_of_primes > 0; prime++) {
		if (sieve[prime]) {
			sum += prime;
			number_of_primes--;

			for (int composite = prime * prime; composite < sieve_size; composite += prime) {
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