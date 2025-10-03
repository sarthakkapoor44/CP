#include <iostream>
using namespace std;
signed main()
{
    long double num = 42;
    long double right = 42, left = 1;
    while (right - left > 1e-6)
    {
        long double mid = (right + left) / 2.000;
        if (mid * mid > num)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << left << endl;
    return 0;
}