#include <iostream>
#include <cmath>

using namespace std;

int comparisons = 0; // Global variable to count comparisons

void Merge(int arrA[], int arrB[], int left, int mid, int right)
{
    int x = left;
    int y = mid;
    int k = left;

    while (x < mid && y <= right)
    {
        comparisons++; // Count each comparison
        if (arrA[x] < arrA[y])
        {
            arrB[k] = arrA[x];
            x++;
            k++;
        }
        else
        {
            arrB[k] = arrA[y];
            y++;
            k++;
        }
    }

    while (x < mid)
    {
        arrB[k] = arrA[x];
        x++;
        k++;
    }

    while (y <= right)
    {
        arrB[k] = arrA[y];
        y++;
        k++;
    }

    for (int i = left; i <= right; i++)
    {
        arrA[i] = arrB[i];
    }
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int m = floor((left + right) / 2);
        MergeSort(arr, left, m);
        MergeSort(arr, m + 1, right);
        int *arrB = new int[right + 1];
        Merge(arr, arrB, left, m + 1, right);
        delete[] arrB;
    }
}

int main()
{
    int arr[] = {1, 5, 8, 32, 4, 90, 5, 3, 6};
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    MergeSort(arr, left, right);

    for (int x = left; x <= right; x++)
        cout << arr[x] << " ";

    cout << "\nComparisons: " << comparisons << endl;

    return 0;
}
