/* Author: Luigi Vincent
*
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Solution {
	public static void main(String[] args) throws FileNotFoundException {
		if (args.length != 1) {
    		System.err.println("Invalid or no arguments.");
    		System.exit(0);
    	}

		try (Scanner input = new Scanner(new File(args[0]))) {
			int numberOfLinesToPrint = Integer.parseInt(input.nextLine());

			Set<String> lineSet = new TreeSet<>(Comparator.comparing(String::length, Comparator.reverseOrder()));
			while (input.hasNextLine()) {
				lineSet.add(input.nextLine());
			}
			printLongestLines(lineSet, numberOfLinesToPrint);
		}
	}

	private static void printLongestLines(Set<String> lineSet, int numberOfLinesToPrint) {
		lineSet.stream().limit(numberOfLinesToPrint).forEach(System.out::println);
	}
}