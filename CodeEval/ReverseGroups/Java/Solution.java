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
				System.out.println(reversedByK(file.nextLine()));
			}
		} catch (FileNotFoundException fnfe) {
			System.err.println("Could not find file.");
		}
	}

	private static String reversedByK(String line) {
		String[] delimited = line.split(";");
		String[] nums = delimited[0].split(",");
		reverseByK(nums, Integer.parseInt(delimited[1]));
		return String.join(",", nums);
	}

	private static void reverseByK(String[] nums, int k) {
		for (int i = 0; i + k <= nums.length; i += k) {
			for (int j = (k - 1) / 2; j >= 0; j--) {
				String swap = nums[i + j];
				nums[i + j] = nums[i + (k - 1) - j];
				nums[i + (k -1) - j] = swap;
			}
		}
	}
}