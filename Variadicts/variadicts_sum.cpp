#include <iostream>
using namespace std;

template<typename T>
T adder(T x)
{
	return x; // call last (this is base function)
}

/*
	The statement adder(1, 3, 5, 7, 9) is evaluated in following manner:
	- First, compiler resolves statements into: first = 1, return value will be: 1 + adder(3, 5, 7, 9)
	- Second, first = 3, return value 3 + adder(5, 7, 9)
	- Third, first = 5, return value 5 + adder(7, 9)
	- first = 7, return value 7 + adder(9). adder(9) is base function adder(T x) so adder(9) return value 9.
	- first = 7 return value: 7 + 9 = 16.
	- first 5, return value: 5 + adder(7, 9) ~ 5 + adder<int, int>, adder<int, int> return value 16 => first = 5, return value = 5 + 16 = 21.
	- first 3, return value: 3 + adder<int, int, int> which return value 21 => first = 3, return value = 3 + 21 = 24.
	- first = 1, return value 1 + adder<int, int, int, int> which return value 24 => first = 1, return value = 1 + 24 = 25.
	so adder<int, int, int, int, int> return value 25.
	int sum = adder(1, 3, 5, 7, 9) => sum = 25
*/

template<typename T, typename... Args>
T adder(T first, Args... args)
{
	return first + adder(args...); 
}

void print()
{
	cout << "I'm an empty function and I am called at last\n";
}

template<typename T, typename... Args>
void print(T var1, Args... var2)
{
	cout << "Var 1: " << endl;
	cout << var1 << endl;
	cout << "\nVar 2: " << endl;
	print(var2...);
}

int main()
{
	int sum = adder(1, 3, 5, 7, 9);
	cout << sum << endl;
	/*print(1, 2, 3.14, "Fuck you", "piece of shit");*/
	return 0;
}