# Author: Luigi Vincent

import sys
import re

def sanitized(line):
	sanitized_line = re.sub("[^a-zA-Z]+", " ", line)
	return sanitized_line.lower().strip()

def main(file):
	with open(file, 'r') as input_file:
		for line in input_file:
			print(sanitized(line))

if __name__ == "__main__":
	try:
		file = sys.argv[1]
		main(file)
	except:
		print("No argument provided.")