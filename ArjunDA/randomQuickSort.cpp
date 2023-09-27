#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int counter;
int Partation(int arr[], int left, int right)
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
            swap(arr[x], arr[y]); // Added a semicolon here
        }
    }

    swap(arr[left], arr[y]);

    return y;
}

int RandPartation(int arr[], int left, int right)
{
    int randomIndex = left + rand() % (right - left + 1);
    swap(arr[left], arr[randomIndex]); // Fixed the swap
    return Partation(arr, left, right);
}

void RandomizeQuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = RandPartation(arr, left, right);
        RandomizeQuickSort(arr, left, pi - 1);
        RandomizeQuickSort(arr, pi + 1, right);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    RandomizeQuickSort(arr, left, right);
    for (int i = left; i <= right; i++)
        cout << " " << arr[i];
    cout << " \n Time Complexiity = " << counter;
    return 0;
}
