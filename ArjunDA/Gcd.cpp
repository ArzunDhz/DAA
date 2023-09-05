#include <iostream>

using namespace std;
int count;
int gcd(int a, int b)
{
    if (a > b)
    {
        while (b != 0)
        {
            count++;
            int r = a % b;
            a = b;
            b = r;
        }
        cout << "GCD = " << a;
    }
    return 0;
}

int main()
{
    int a, b;
    cout << "Enter two Number ";
    cin >> a >> b;
    gcd(a, b);
    cout << " \n Time Complexity = " << count;
}