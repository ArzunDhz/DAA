#include <iostream>
using namespace std;

int f1 = 1;
int f2 = 1;
int f = 0;
int c = 0;

int fibo(int n)
{
    for (int i = 3; i <= n; i++)
    {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        cout << "," << f;
        c++;
    }
    return 0;
}

int main()
{

    cout << f1 << "," << f2;
    int n;
    fibo(10);
    cout << " \n Time Complexity  = " << c;
    return 0;
}