###Challenge
Encode a binary code within words.

###Specifications
1. The first argument is a path to a file.
2. The file contains multiple lines.
3. Each line is a test case represented by a space separated word and a binary code.
4. For each test case, print the binary masked word where the mask alters the word in the following way:
 - If the bit is 1, change the letter to upper case.
 - If the bit is 0, leave the letter as is.

###Constraints
1. Words are from 1 to 20 letters long.
2. The length of each word is equal to the length of the binary code.
3. Words are always in lower case.
4. The number of test cases is 40.


**Sample Input**
>hello 11001  
world 10000  
cba 111

**Sample Output**
>HEllO  
World  
CBA

[Source](https://www.codeeval.com/open_challenges/199/)