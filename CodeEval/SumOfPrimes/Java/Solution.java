/* Author: Luigi Vincent
*
*/

public class Solution {
	public static void main(String[] args) {
		System.out.println(sumPrimes(1000));
	}

	private static int sumPrimes(int numberOfPrimes) {
		int sum = 0;
		boolean[] sieve = new boolean[numberOfPrimes * 20];
		for (int prime = 2; numberOfPrimes > 0; prime++) {
			if (!sieve[prime]) {
				sum += prime;
				numberOfPrimes--;

				for (int composite = prime * prime; composite < sieve.length; composite += prime) {
					sieve[composite] = true;
				}
			}
		}

		return sum;
	}
}