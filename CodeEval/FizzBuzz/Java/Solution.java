/* Author: Luigi Vincent
*
*/

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Solution {
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("Invalid or no arguments.");
			System.exit(1);
		}

		try (Stream<String> line = Files.lines(Paths.get(args[0]))) {
			line.forEach(Solution::printBuzzed);
		} catch (IOException ioe) {
			System.err.println("File not found / Could not read file.");
		}
	}

	private static void printBuzzed(String line) {
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

		System.out.print(result.toString());
	}
}