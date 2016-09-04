/* Author: Luigi Vincent 
*
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		if (args.length == 0) {
			System.out.println("No file path provided.");
			System.exit(1);
		}

		if (args.length >= 2) {
			System.out.println("Excessive arguments only the first will be considered.");
		}

		try (Scanner file = new Scanner(new File(args[0]))) {
			while (file.hasNextLine()) {
				System.out.println(swapped(file.nextLine()));
			}
		} catch (FileNotFoundException ex) {
			System.err.println("Could not find file.");
		}
	}

	private static String swapped(String line) {
		StringBuilder swapped = new StringBuilder();
		StringBuilder word = new StringBuilder();
		char temp = ' ';
		boolean swapping = false;

		for (int i = 0; i < line.length(); i++) {
			char c = line.charAt(i);
			if (Character.isDigit(c)) {
				if (!swapping) {
					temp = c;
					swapping = true;
				} else {
					swapped.append(' ').append(c).append(word).append(temp);
					word.setLength(0);
					swapping = false;
				}
			} else if (c != ' ') {
				word.append(c);
			}
		}

		return swapped.substring(1);
	}
}