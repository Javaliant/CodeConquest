# Author: Luigi Vincent

import fileinput
import re
import sys

MORSE_ALPHABET = {
	' '		: ' ',
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
    return re.sub(' ?( |[.-]*)', lambda m: MORSE_ALPHABET.get(m.group(1)), morse)

def main():
    try:
        for line in fileinput.input():
            print(decode(line), end = '')
    except FileNotFoundError as e:
        sys.exit(e)

if __name__ == "__main__":
    main()