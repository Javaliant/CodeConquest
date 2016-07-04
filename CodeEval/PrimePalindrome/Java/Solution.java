/* Author: Luigi Vincent
*
*/

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class Solution {
	public static void main(String[] args) {
		System.out.println(largestPrimePalindrome(1000));
	}

	private static int largestPrimePalindrome(int limit) {
		if (limit < 2) {
			throw new IllegalArgumentException("There are no primes under 2");
		}

		List<Integer> primes = primesUnder(limit);
		ListIterator<Integer> palindromeFinder = primes.listIterator(primes.size());
		int possiblePalindrome = 0;

		while (palindromeFinder.hasPrevious()) {
			possiblePalindrome = palindromeFinder.previous();
			if (isPalindrome(possiblePalindrome)) {
				break;
			}
		}

		return possiblePalindrome;
	}

	private static List<Integer> primesUnder(int limit) {
		List<Integer> primes = new ArrayList<>();
		boolean[] sieve = new boolean[limit];
		Arrays.fill(sieve, true);

		for (int prime = 2; prime < limit; prime++) {
			if (sieve[prime]) {
				primes.add(prime);

				for (int composite = prime * prime; composite < limit; composite += prime) {
					sieve[composite] = false;
				}
			}
		}

		return primes;
	}

	private static boolean isPalindrome(int input) {
		return input == reverse(input, 10);
	}

	private static int reverse(int input, int base) {
		int reversed = 0;

		while (input != 0) {
			reversed *= base;
			reversed += (input % base);
			input /= base;
		}

		return reversed;
	}
}