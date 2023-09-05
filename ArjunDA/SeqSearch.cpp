#include <iostream>

using namespace std;

int counter;
int SeqSearch(int a[], int l, int n)
{
    for (int i = 0; i < l; i++)
    {
        counter++;
        if (a[i] == n)
            return 1;
    }

    return 0;
}
int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 22};
    int n;
    cout << "Enter the Number you want to find ";
    cin >> n;
    int length = (sizeof(array) / sizeof(array[0]));
    if (SeqSearch(array, length, n))
        cout << "Found";
    else
        cout << "Not found ";

    cout << " \n Time Complexity = " << counter;
}