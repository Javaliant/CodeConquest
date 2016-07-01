# Author: Luigi Vincent
def sum_of_primes(number_of_primes):
	prime_sum = 0
	sieve = [True] * (number_of_primes * 20)
	prime = 2
	while (number_of_primes > 0):
		if (sieve[prime]):
			prime_sum += prime
			number_of_primes -= 1
			for composite in range(prime * prime, len(sieve), prime):
				sieve[composite] = False
		prime += 1

	return prime_sum

if __name__ == "__main__":
	print(sum_of_primes(100000))