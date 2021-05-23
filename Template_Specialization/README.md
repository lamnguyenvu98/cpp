Input Format

	The first line contains t, the number of test cases.
	Each of the t subsequent lines contains two space-separated integers. The first integer is a color value, c, and the second integer is a fruit value, f.

Ouput Format

	The locked stub code in your editor prints t lines containing the color name and the fruit name corresponding to the input enumeration index.

Sample Input

	2
	1 0
	3 3

Sample Output

	green apple
	unknown unknown

Explanation

	since t = 2 => 2 lines of input.
	first line: 2 index values are 1 and 0, correspond to green in the color enumeration and apple in fruit enumeration.
	Second line: two input values, 3 and 3, are outside of the range of our enums. Thus, we print: unknown unknown.
	Fruit: 0 - apple, 1 - orange, 2 - pear.
	Color: 0 - red, 1 - green, 2 - orange.

Source: https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem/
