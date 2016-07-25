/* Author: Luigi Vincent
*
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println(args.length > 1 ? "Excessive arguments, expected: 1." : "No arguments provided.");
			System.exit(1);
		}

		try (Scanner input = new Scanner(new File(args[0]))) {
			while (input.hasNextLine()) {
				System.out.println(permutateString(sortString(input.nextLine())));
			}
		} catch (FileNotFoundException fnfe) {
			fnfe.printStackTrace();
		}
	}

	private static void permutate(String prefix, String str, StringBuilder sb) {
    	int len = str.length();

    	if (len == 1) {
    		sb.append(',').append(prefix).append(str);
    	} else {
        	for (int i = 0; i < len; i++) {
            	permutate(prefix + str.charAt(i), str.substring(0, i) + str.substring(i + 1, len), sb);
        	}
    	}
	}

	private static String permutateString(String input) {
		StringBuilder characterBuilder = new StringBuilder();
		permutate("", input, characterBuilder);
		return characterBuilder.substring(1);
	}

	private static String sortString(String input) {
		char[] temp = input.toCharArray();
		Arrays.sort(temp);
		return String.valueOf(temp);
	}
}