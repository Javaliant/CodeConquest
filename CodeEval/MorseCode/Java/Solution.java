/* Author: Luigi Vincent
*
*/

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
	private static final Map<String, Character> morseAlphabet = new HashMap<>();

	static {
		morseAlphabet.put(".-", 'A');
		morseAlphabet.put("-...", 'B');
		morseAlphabet.put("-.-.", 'C');
		morseAlphabet.put("-..", 'D');
		morseAlphabet.put(".", 'E');
		morseAlphabet.put("..-.", 'F');
		morseAlphabet.put("--.", 'G');
		morseAlphabet.put("....", 'H');
		morseAlphabet.put("..", 'I');
		morseAlphabet.put(".---", 'J');
		morseAlphabet.put("-.-", 'K');
		morseAlphabet.put(".-..", 'L');
		morseAlphabet.put("--", 'M');
		morseAlphabet.put("-.", 'N');
		morseAlphabet.put("---", 'O');
		morseAlphabet.put(".--.", 'P');
		morseAlphabet.put("--.-", 'Q');
		morseAlphabet.put(".-.", 'R');
		morseAlphabet.put("...", 'S');
		morseAlphabet.put("-", 'T');
		morseAlphabet.put("..-", 'U');
		morseAlphabet.put("...-", 'V');
		morseAlphabet.put(".--", 'W');
		morseAlphabet.put("-..-", 'X');
		morseAlphabet.put("-.--", 'Y');
		morseAlphabet.put("--..", 'Z');
		morseAlphabet.put("-----", '0');
		morseAlphabet.put(".----", '1');
		morseAlphabet.put("..---", '2');
		morseAlphabet.put("...--", '3');
		morseAlphabet.put("....-", '4');
		morseAlphabet.put(".....", '5');
		morseAlphabet.put("-....", '6');
		morseAlphabet.put("--...", '7');
		morseAlphabet.put("---..", '8');
		morseAlphabet.put("----.", '9');
	}

	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println(args.length > 1 ? "Excessive arguments, expected: 1" : "No arguments provided.");
			System.exit(1);
		}

		try (Scanner fileScanner = new Scanner(new File(args[0]))) {
			StringBuilder decoded = new StringBuilder();
			while (fileScanner.hasNextLine()) {
				decoded.append('\n').append(decode(fileScanner.nextLine()));
			}
			System.out.println(decoded.substring(1));
		} catch (FileNotFoundException fnfe) {
			fnfe.printStackTrace();
		}
	}

	private static String decode(String morse) {
		StringBuilder decoded = new StringBuilder();

		String[] words = morse.split("\\s{2}");
		for (String word : words) {
			decoded.append(' ');
			String[] letters = word.split("\\s");
			for (String letter : letters) {
				decoded.append(morseAlphabet.get(letter));
			}
		}

		return decoded.substring(1);
	}
}