#include <iostream>
using namespace std;

int counter;
int BinarySearch(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {

        counter++;
        int mid = (left + right) / 2;

        if (arr[mid] == key)
        {
            return 1;
        }
        else if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "enter element to serach = ";
    cin >> key;
    if (BinarySearch(arr, length, key))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    cout << "Time complexity  = " << counter;
}
