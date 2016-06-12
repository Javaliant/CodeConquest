/* Author: Luigi Vincent
*
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.NavigableMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Solution {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File(args[0]));
		int numberOfLinesToPrint = Integer.parseInt(input.nextLine());

		NavigableMap<Integer, String> lineMap = new TreeMap<>();
		while (input.hasNextLine()) {
			addLine(lineMap, input.nextLine());
		}
		printLongestLines(lineMap, numberOfLinesToPrint);
	}

	private static void printLongestLines(NavigableMap<Integer, String> lineMap, int numberOfLinesToPrint) {
		for (int i = 0; i < numberOfLinesToPrint; i++) {
			System.out.println(lineMap.pollLastEntry().getValue());
		}
	}

	private static void addLine(NavigableMap<Integer, String> lineMap, String line) {
		lineMap.put(line.length(), line);
	}
}