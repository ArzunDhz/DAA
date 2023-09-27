#include <iostream>
#include <cstdlib>

using namespace std;

int counter = 0; // Initialize a counter for counter

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

int RandomizedPartition(int arr[], int left, int right)
{
    int randomIndex = left + rand() % (right - left + 1);
    swap(arr[left], arr[randomIndex]);
    return Partition(arr, left, right);
}

int RandomizedSelect(int arr[], int left, int right, int index)
{
    if (left == right)
    {
        return arr[left];
    }

    int p = RandomizedPartition(arr, left, right);
    int k = p - left + 1;

    if (index == k)
    {
        return arr[p];
    }
    else if (index < k)
    {
        return RandomizedSelect(arr, left, p - 1, index);
    }
    else
    {
        return RandomizedSelect(arr, p + 1, right, index - k);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    int k = 5;
    int result = RandomizedSelect(arr, left, right, k);
    cout << "The " << k << "th smallest element is: " << result << endl;
    cout << "Time Complexity = " << counter << endl;

    return 0;
}
