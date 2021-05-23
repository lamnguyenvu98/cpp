#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()

// This is base
template<bool a>
int reversed_binary_value()
{
    return a;
}

/*
    x << y mean x = x * (2^(y))
    6 in binary is 110 so reversed binary order will be 011.
    reserves_binary_order<false, true, true>
    First, reversed_binary_order will return 0 + (reversed_binary_order<true, true> << 1)
    Then return 1 + (reversed_binary_order<true> << 1). reversed_binary_order<true> call the base and will return true (or 1).
    So 1 + (1 << 1) = 1 + ( 1 * 2^(1) ) = 3
    0 + (reversed_binary_order<true, true> << 1) will be 0 + (3 << 1) = 0 + (3 * 2^(1)) = 6.
    Finally, reserves_binary_order<false, true, true> will return 6.

    6 in binary is 110 and reserved order will be 011. 011 = 3 in decimal
    to return value 6 just 3 << 1 = 3 * 2^(1) = 6.
*/

template<bool a, bool b, bool... d>
int reversed_binary_value()
{
    return a + (reversed_binary_value<b, d...>() << 1);
}


template <int n, bool...digits>
struct CheckValues {
    static void check(int x, int y)
    {
        CheckValues<n - 1, 0, digits...>::check(x, y);
        CheckValues<n - 1, 1, digits...>::check(x, y);
    }
};

template <bool...digits>
struct CheckValues<0, digits...> {
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x);
    }
};

int main()
{
    int t; std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
