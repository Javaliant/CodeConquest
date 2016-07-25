**Java** [![Code Review](http://www.zomis.net/codereview/shield/?qid=97414)](http://codereview.stackexchange.com/q/97414/49181)

###Challenge
Write a program which prints out the permutations of a string.

###Specifications
1. The first argument is a path to a file.
2. The file contains multiple lines.
3. Each line is an input string.
4. Print out the permutations of the input string, separated by a comma, in alphabetical order.
 - Digits < upper case letters < lower case letters.
 - The sorting should be in ascending order.

###Constraints
1. The input file is correctly formatted.

**Sample Input**
>.hat  
abc  
Zu6

**Sample Output**
>aht,ath,hat,hta,tah,tha  
abc,acb,bac,bca,cab,cba  
6Zu,6uZ,Z6u,Zu6,u6Z,uZ6

[Source](https://www.codeeval.com/open_challenges/14/)