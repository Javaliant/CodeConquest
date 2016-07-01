# Author: Luigi Vincent

def reverse(integer, base = 10):
	result = 0

	while integer:
		integer, remainder = divmod(integer, base)
		result = base * result + remainder
	return result

def is_palindromic(integer):
	return integer == reverse(integer)

def compute_primes_below(limit):
	primes = []
	sieve = [True] * limit

	for prime in range(2, limit):
		if sieve[prime]:
			primes.append(prime)
			for composite in range(prime * prime, limit, prime):
				sieve[composite] = False
	return primes


def compute_largest_prime_palindrome_below(limit):
	primes = compute_primes_below(limit)
	for prime in reversed(primes):
		if is_palindromic(prime):
			return prime

if __name__ == "__main__":
	print(compute_largest_prime_palindrome_below(1000))