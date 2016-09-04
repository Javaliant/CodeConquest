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
				System.out.println(reversed(file.nextLine()));
			}
		} catch (FileNotFoundException fnfe) {
			System.err.println("Could not find file.");
		}
	}

	private static String reversed(String line) {
		String[] helper = line.split(";");
		int k = Integer.parseInt(helper[1]);
		if (k == 0) {
			return helper[0];
		}
		return reversedByK(helper[0].split(","), k);
	}

	private static String reversedByK(String[] nums, int k) {
		StringBuilder result = new StringBuilder();
		for (int i = k - 1; i < nums.length; i += k) {
			for (int j = i; i - j <= k - 1; j--) {
				result.append(',').append(nums[j]);
			}
		}

		for (int i = nums.length - nums.length % k; i < nums.length; i++) {
			result.append(',').append(nums[i]);
		}
		return result.substring(1);
	}
}