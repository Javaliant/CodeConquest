# Author: Luigi Vincent

import sys
import re

morse_alphabet = {
	''		: ' ',
	'.-'    : 'A',
	'-...'  : 'B',
	'-.-.'  : 'C',
	'-..'   : 'D',
	'.'     : 'E',
	'..-.'  : 'F',
	'--.'   : 'G',
	'....'  : 'H',
	'..'    : 'I',
	'.---'  : 'J',
	'-.-'   : 'K',
	'.-..'  : 'L',
	'--'    : 'M',
	'-.'    : 'N',
	'---'   : 'O',
	'.--.'  : 'P',
	'--.-'  : 'Q',
	'.-.'   : 'R',
	'...'   : 'S',
	'-'     : 'T',
	'..-'   : 'U',
	'...-'  : 'V',
	'.--'   : 'W',
	'-..-'  : 'X',
	'-.--'  : 'Y',
	'--..'  : 'Z',
	'-----' : '0',
	'.----' : '1',
	'..---' : '2',
	'...--' : '3',
	'....-' : '4',
	'.....' : '5',
	'-....' : '6',
	'--...' : '7',
	'---..' : '8',
	'----.' : '9'
}

def decode(morse):
	decoded = ''
	line = re.split('\s', morse)
	for letter in line:
		decoded += morse_alphabet.get(letter)
	return decoded

def main(filename):
	with open(filename) as input_file:
		for line in input_file:
			print(decode(line))

if __name__ == "__main__":
	try:
		main(sys.argv[1])
	except:
		sys.exit("No argument provided / file not found.")