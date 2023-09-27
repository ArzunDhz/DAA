
///

#include <iostream>
using namespace std;

int counter = 0;

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int x = left;
    int y = right;

    while (x < y)
    {
        while (arr[x] <= pivot)
        {
            x++;
            counter++;
        }
        while (arr[y] > pivot)
        {
            y--;
            counter++;
        }
        if (x < y)
        {
            swap(arr[x], arr[y]);
        }
    }

    swap(arr[left], arr[y]);
    return y;
}

void QuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = Partition(arr, left, right);
        QuickSort(arr, left, pi - 1);
        QuickSort(arr, pi + 1, right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    QuickSort(arr, left, right);

    for (int x = left; x <= right; x++)
        cout << arr[x] << " ";

    cout << endl;

    cout << "Time Compexity  = " << counter << endl;
    return 0;
}
