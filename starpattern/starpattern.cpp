#include <iostream>
using namespace std;

void TamGiacCan(int h)
{
    int m = h, n = h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= 2*h - 1; j++)
        {
            if (j >= m && j <= n)
                cout << "*";
            else cout << " ";
        }
        m--; n++;
        cout << endl;
    }
}

void hbh(int n)
{
    int idx = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2*n - i; j++)
        {
            if ( j < idx )
                cout << " ";
            else cout << "*";
        }
        idx--;
        cout << endl;
    }
}

void TamGiacDeu(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = n - i; k > 0; k--)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    TamGiacCan(n);
  
    return 0;
}
