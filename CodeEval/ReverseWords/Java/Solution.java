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
			line.forEach(Solution::printReversed);
		} catch (IOException ioe) {
			System.err.println("File not found / Could not read file.");
		}
	}

	private static void printReversed(String line) {
		String[] words = line.split("\\s+");
		for (int i = words.length - 1; i > 0; i--) {
			System.out.print(words[i] + ' ');
		}
		System.out.println(words[0]);
	}
}