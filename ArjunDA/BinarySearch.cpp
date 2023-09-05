#include <iostream>
using namespace std;

int counter = 0;

int BinarySearch(int a[], int l, int r, int key)
{
    if (l <= r)
    {
        int m = (r + l) / 2;
        counter++;
        if (a[m] == key)
        {

            return 1;
        }
        if (a[m] > key)
        {

            return BinarySearch(a, l, m - 1, key);
        }
        else
        {

            return BinarySearch(a, m + 1, r, key);
        }
    }

    return 0;
};

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrLength = sizeof(array) / sizeof(array[0]);
    int key;
    cout << "Enter Number you want to search ";
    cin >> key;
    if (BinarySearch(array, 0, arrLength - 1, key))
    {
        cout << "Found"
             << "With Time Complexity = " << counter;
    }
    else
    {
        cout << "Not Found"
             << " Time Complexity  = " << counter;
    }

    return 0;
}