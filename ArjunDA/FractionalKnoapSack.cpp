#include <iostream>

using namespace std;
int counter;
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, bagCapacity;
    bagCapacity = static_cast<int>(capacity);

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        counter++;
        if (weight[i] > bagCapacity)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            bagCapacity = bagCapacity - weight[i];
        }
    }

    if (i < n)
        x[i] = bagCapacity / weight[i];

    tp = tp + (x[i] * profit[i]);

    cout << "The result portion is:- ";
    for (i = 0; i < n; i++)
        cout << x[i] << "\t";

    cout << "\nMaximum profit is:- " << tp << endl;
}

int main()
{
    int num = 5;
    float weight[5] = {10, 20, 30, 40, 50};
    float profit[5] = {60, 100, 120, 140, 160};
    float capacity = 50;

    float ratio[20], temp;

    for (int i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            counter++;
            if (ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    knapsack(num, weight, profit, capacity);
    cout << "Time Complexity = " << counter;
    return 0;
}
