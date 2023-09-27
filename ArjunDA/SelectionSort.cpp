
#include <iostream>

using namespace std;

int count;
void SelectionSort(int a[], int l)
{
    int currentMinIndex;

    for (int i = 0; i < l - 1; i++)
    {
        currentMinIndex = i;

        for (int j = i + 1; j < l; j++)
        {
            count++;
            if (a[j] < a[currentMinIndex])
            {
                currentMinIndex = j;
            }
        }
        if (currentMinIndex != i)
        {
            swap(a[i], a[currentMinIndex]); // i = 0 so we  sawp with first element initially
        }
    }
}

int main()
{
    int array[] = {1, 5, 2, 8, 9, 10, 3};
    int length = sizeof(array) / sizeof(array[0]);
    SelectionSort(array, length);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << endl;
    }

    cout << "Time Complexity  = " << count;
}