Input Format

	The first line contains an integer, t, the number of test cases. 
	Each of the subsequent lines contains a test case. A test case is described as 2 space-separated integers, x and , y respectively.
	x is value to compare against.
	y represents the range to compare: (64 * y) to (64 * y + 63). If y = 0, range will be 0 to 63. If y = 1, range will be 64 to 127...

Output Format

	Each line of output contains 64 binary characters (i.e., 1's and 0's). 
	Each character represents one value in the range. 
	The first character corresponds to the first value in the range. 
	The last character corresponds to the last value in the range. 
	The character is 1 if the value in the range matches X; otherwise, the character is 0.

Sample Input

	2
	65 1
	10 0

Sample Output

	0100000000000000000000000000000000000000000000000000000000000000
	0000000000100000000000000000000000000000000000000000000000000000

Explanation

	The second character on the first line is a 1, because the second value in the range 64..127 is 65 and x is 65.
	The eleventh character on the second line is a 1, because the eleventh value in the range 0..63 is 10 and x is 10.
	All other characters are zero, because the corresponding values in the range do not match x.

Source: https://www.hackerrank.com/challenges/cpp-variadics/problem
