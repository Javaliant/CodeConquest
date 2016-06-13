**Java** [![Code Review](http://www.zomis.net/codereview/shield/?qid=97356)](http://codereview.stackexchange.com/q/97356/49181)
**C** [![Code Review](http://www.zomis.net/codereview/shield/?qid=131730)](http://codereview.stackexchange.com/q/131730/49181)
**Python** [![Code Review](http://www.zomis.net/codereview/shield/?qid=131804)](http://codereview.stackexchange.com/q/131804/49181)

###Challenge
Given a list of words mixed with extra symbols. Write a program that will clean up the words from extra numbers and symbols.

###Specifications
1. The first argument is a path to a file.   
2. Each line includes a test case.
3. Each test case is a list of words.
4. Letters are both lowercase and uppercase, and mixed with extra symbols.
5. Print the words separated by spaces in lowercase letters.

###Constraints
1. The length of a test case together with extra symbols can be in a range from 10 to 100 symbols.
2. The number of test cases is 40.

**Input Sample**
>(--9Hello----World...--)  
Can 0$9 ---you~  
13What213are;11you-123+138doing7

**Output Sample**
>hello world  
can you  
what are you doing

[Source](https://www.codeeval.com/open_challenges/205/)