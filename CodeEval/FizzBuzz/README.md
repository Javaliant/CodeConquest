**Java** [![Code Review](http://www.zomis.net/codereview/shield/?qid=77569)](http://codereview.stackexchange.com/q/77569/49181)
**C** [![Code Review](http://www.zomis.net/codereview/shield/?qid=132307)](http://codereview.stackexchange.com/q/132307/49181)

###Challenge
Given a test case print out a FizzBuzz Series. 

###Specifications
1. The first argument is a path to a file.
2. Each line includes a test case.
3. Each test case is comprised of three spaced delimited integers. 
	- The first two integers are the dividers X and Y.
	- The third integer, N is how far to count.
4. Print out the series 1 through N, replacing numbers divisible by X with F, numbers divisible by Y with B and numbers divisible by both with FB.

###Constraints
1. The input file is formatted correctly.
2. The numbers are valid positive integers.
3. X is in range [1, 20]
4. Y is in range [1, 20]
5. N is in range [21, 100]
6. Output should be one line per set with no trailing or empty spaces.

**Input Sample**
>3 5 10  
2 7 15

**Output Sample**
>1 2 F 4 B F 7 8 F B  
1 F 3 F 5 F B F 9 F 11 F 13 FB 15

[Source](https://www.codeeval.com/open_challenges/1/)