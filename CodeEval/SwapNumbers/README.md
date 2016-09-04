###Challenge
Swap the numbers surrounding the words in sentences.

###Specification
1. The first argument is a path to a file.
2. The file contains multiple lines.
3. Each line is a test case represented by a sentence.
4. Each sentence begins and ends with a number.
5. Print out the sentence obtained by swapping the numbers surrounding each word.


###Constraints
1. The suffix and the prefix of each word may be equal.
2. Sentences are from 1 to 17 words long.
3. The number of test cases is 40.
4. All characters are ASCII.
5. The numbers are single digit positive intgers 0-9. 


**Sample Input**
>4Always0 5look8 4on9 7the2 4bright8 9side7 3of8 5life5  
5Nobody5 7expects3 5the4 6Spanish4 9inquisition0

**Sample Output**
>0Always4 8look5 9on4 2the7 8bright4 7side9 8of3 5life5  
5Nobody5 3expects7 4the5 4Spanish6 0inquisition9

[Source](https://www.codeeval.com/open_challenges/196/)