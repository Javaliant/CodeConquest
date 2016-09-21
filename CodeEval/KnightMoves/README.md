**C** [![Code Review](http://www.zomis.net/codereview/shield/?qid=141688)](http://codereview.stackexchange.com/q/141688/49181)

###Challenge
Find all possible moves for a knight on an empty chessboard.

###Specifications
1. The first argument is a path to a file.
2. The file contains multiple lines.
3. Each line is a test case representing the position of the knight in CN form.
 - C is a letter from “a” to “h” and denotes a column.
 - N is a number from 1 to 8 and denotes a row.
4. For each test case, print all positions for the next move of the knight ordered alphabetically.

###Constraints
1. The number of test cases is 40.


**Sample Input**
>g2  
a1  
d6  
e5  
b1

**Sample Output**
>e1 e3 f4 h4  
b3 c2  
b5 b7 c4 c8 e4 e8 f5 f7  
c4 c6 d3 d7 f3 f7 g4 g6  
a3 c3 d2

[Source](https://www.codeeval.com/open_challenges/180/)