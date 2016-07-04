# Author: Luigi Vincent

def reverse(integer, base = 10):
	result = 0

	while integer:
		integer, remainder = divmod(integer, base)
		result = base * result + remainder
	return result

def is_palindrome(integer):
	return integer == reverse(integer)

def primes_below(limit):
	primes = []
	sieve = [True] * limit

	for prime in range(2, limit):
		if sieve[prime]:
			primes.append(prime)
			for composite in range(prime * prime, limit, prime):
				sieve[composite] = False
	return primes


def largest_prime_palindrome(limit):
	primes = primes_below(limit)

	for prime in reversed(primes):
		if is_palindrome(prime):
			return prime

if __name__ == "__main__":
	print(largest_prime_palindrome(1000))