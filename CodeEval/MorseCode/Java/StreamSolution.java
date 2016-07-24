/* Author: Luigi Vincent
* A solution applying java 8 streams.
*/

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

class StreamSolution {
	private static final Map<String, String> morseAlphabet = new HashMap<>();

	static {
		morseAlphabet.put("", " ");
		morseAlphabet.put(".-", "A");
		morseAlphabet.put("-...", "B");
		morseAlphabet.put("-.-.", "C");
		morseAlphabet.put("-..", "D");
		morseAlphabet.put(".", "E");
		morseAlphabet.put("..-.", "F");
		morseAlphabet.put("--.", "G");
		morseAlphabet.put("....", "H");
		morseAlphabet.put("..", "I");
		morseAlphabet.put(".---", "J");
		morseAlphabet.put("-.-", "K");
		morseAlphabet.put(".-..", "L");
		morseAlphabet.put("--", "M");
		morseAlphabet.put("-.", "N");
		morseAlphabet.put("---", "O");
		morseAlphabet.put(".--.", "P");
		morseAlphabet.put("--.-", "Q");
		morseAlphabet.put(".-.", "R");
		morseAlphabet.put("...", "S");
		morseAlphabet.put("-", "T");
		morseAlphabet.put("..-", "U");
		morseAlphabet.put("...-", "V");
		morseAlphabet.put(".--", "W");
		morseAlphabet.put("-..-", "X");
		morseAlphabet.put("-.--", "Y");
		morseAlphabet.put("--..", "Z");
		morseAlphabet.put("-----", "0");
		morseAlphabet.put(".----", "1");
		morseAlphabet.put("..---", "2");
		morseAlphabet.put("...--", "3");
		morseAlphabet.put("....-", "4");
		morseAlphabet.put(".....", "5");
		morseAlphabet.put("-....", "6");
		morseAlphabet.put("--...", "7");
		morseAlphabet.put("---..", "8");
		morseAlphabet.put("----.", "9");
	}


	private static final Pattern charsplit = Pattern.compile("\\s+");

	private static final String decodeLine(String line) {
		return charsplit.splitAsStream(line)
			.map(letter -> morseAlphabet.get(letter))
			.collect(Collectors.joining(""));
	}

	public static final String decode(List<String> data) {
		return data.stream()
			.map(StreamSolution::decodeLine)
			.collect(Collectors.joining("\n"));
	}

	public static void main (String[] args) throws IOException {
		System.out.println(StreamSolution.decode(Files.readAllLines(Paths.get(args[0]))));
	}
}