# Author: Luigi Vincent

import sys
import re

def sanitized(line):
	sanitized_line = re.sub("[^a-zA-Z]+", " ", line)
	return sanitized_line.lower().strip()

def main(filename):
	with open(filename) as input_file:
		for line in input_file:
			print(sanitized(line))

if __name__ == "__main__":
	try:
		main(sys.argv[1])
	except:
		print("No argument provided.")