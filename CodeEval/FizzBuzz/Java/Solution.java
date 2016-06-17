/* Author: Luigi Vincent
*
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner fileScanner = new Scanner(new File(args[0]));
		while (fileScanner.hasNextLine()) {
			System.out.print(buzzified(fileScanner.nextLine()));
		}
	}

	private static String buzzified(String line) {
		String[] numberStrings = line.split(" ");
		int fizz = Integer.parseInt(numberStrings[0]);
		int buzz = Integer.parseInt(numberStrings[1]);
		int count = Integer.parseInt(numberStrings[2]);

		StringBuilder result = new StringBuilder();
		for (int i = 1; i <= count; i++) {
			if (i % fizz == 0 && i % buzz == 0) {
				result.append("FB");
			} else if (i % fizz == 0) {
				result.append('F');
			} else if (i % buzz == 0) {
				result.append('B');
			} else {
				result.append(i);
			}

			result.append(i < count ? ' ' : '\n');
		}

		return result.toString();
	}
}