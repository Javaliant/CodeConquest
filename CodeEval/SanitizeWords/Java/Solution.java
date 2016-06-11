/* Author: Luigi Vincent
*
*/

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Solution {
    public static void main(String[] args) {
    	if (args.length != 1) {
    		System.err.println("Invalid or no arguments.");
    		System.exit(0);
    	}

    	try(BufferedReader reader = new BufferedReader(new FileReader(args[0]))) {
    		String line;
    		while((line = reader.readLine()) != null) {
            	System.out.println(sanitized(line));
        	}
    	} catch (IOException ioe) {
    		System.err.println(args[0] + " not found.");
    	}
    }

    private static String sanitized(String input) {
        return input.replaceAll("[^a-zA-Z]+", " ").toLowerCase().trim();
    }
}