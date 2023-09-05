

#include <iostream>

using namespace std;

int count = 0;

int BubbleSort(int a[], int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - 1; j++)
        {
            count++;
            if (a[j] > a[j + 1])
            {

                swap(a[j], a[j + 1]);
            }
        }
    }

    return 0;
}

int main()
{
    int array[] = {1, 9, 7, 2, 5, 8, 6};
    int length = sizeof(array) / sizeof(array[0]);
    BubbleSort(array, length);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << endl;
    }
    cout << "Time Complexity = " << count;
    return 0;
}