# Author: Luigi Vincent

import sys

def sanitized(line):
	need_space = False
	match_found = False
	sanitized_line = ""

	for character in line:
		if character.isalpha():
			if need_space:
				sanitized_line += " "
				need_space = False
			sanitized_line += character
			match_found = True
		elif match_found:
			need_space = True
	return sanitized_line.lower()
	

with open(sys.argv[1], 'r') as input_file:
	for line in input_file:
		print(sanitized(line))