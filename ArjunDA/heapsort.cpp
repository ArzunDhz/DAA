#include <bits/stdc++.h>
using namespace std;

int counter = 0;

void Heapify(int arr[], int size, int currentIndex)
{
    int largestIndex = currentIndex;
    int left = currentIndex * 2;
    int right = currentIndex * 2 + 1;

    if (left < size)
    {
        counter++;
        if (arr[left] > arr[largestIndex])
        {
            largestIndex = left;
        }
    }
    if (right < size)
    {
        counter++;
        if (arr[right] > arr[largestIndex])
        {
            largestIndex = right;
        }
    }

    if (largestIndex != currentIndex)
    {
        swap(arr[currentIndex], arr[largestIndex]);
        Heapify(arr, size, largestIndex);
    }
}

void BuildHeap(int arr[], int size)
{
    for (int i = size / 2; i >= 0; i--)
    {
        Heapify(arr, size, i);
    }
}

void HeapSort(int arr[], int size)
{
    BuildHeap(arr, size);

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {1, 4, 6, 7, 8, 9, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\n Time complexity =  " << counter << endl;

    return 0;
}
