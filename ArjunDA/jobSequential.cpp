#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAX 100

using namespace std;

struct Job
{
    string id;
    int deadline;
    int profit;
};

int minValue(int x, int y)
{
    return (x < y) ? x : y;
}

void jobSequencingWithDeadline(Job jobs[], int n);

int main()
{
    // variables
    int i, j;

    // jobs with deadline and profit
    Job jobs[5] = {
        {"j1", 2, 60},
        {"j2", 1, 100},
        {"j3", 3, 20},
        {"j4", 2, 40},
        {"j5", 1, 20},
    };

    // number of jobs
    int n = 5;

    // sort the jobs profit-wise in descending order with a comparison counter
    int counter = 0;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            counter++; // Increment the comparison counter
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                swap(jobs[j + 1], jobs[j]);
            }
        }
    }

    cout << setw(10) << "Job" << setw(10) << "Deadline" << setw(10) << "Profit" << endl;
    for (i = 0; i < n; i++)
    {
        cout << setw(10) << jobs[i].id << setw(10) << jobs[i].deadline << setw(10) << jobs[i].profit << endl;
    }

    jobSequencingWithDeadline(jobs, n);

    cout << "Number of comparisons during sorting: " << counter << endl;
    return 0;
}

void jobSequencingWithDeadline(Job jobs[], int n)
{
    // variables
    int i, k, maxprofit;

    // free time slots
    int timeslot[MAX];

    // filled time slots
    int filledTimeSlot = 0;

    // find max deadline value
    int dmax = 0;
    for (i = 0; i < n; i++)
    {
        if (jobs[i].deadline > dmax)
        {
            dmax = jobs[i].deadline;
        }
    }

    // free time slots initially set to -1 [-1 denotes EMPTY]
    for (i = 1; i <= dmax; i++)
    {
        timeslot[i] = -1;
    }

    cout << "dmax: " << dmax << endl;

    for (i = 1; i <= n; i++)
    {
        k = minValue(dmax, jobs[i - 1].deadline);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i - 1;
                filledTimeSlot++;
                break;
            }
            k--;
        }

        // if all time slots are filled, then stop
        if (filledTimeSlot == dmax)
        {
            break;
        }
    }

    // required jobs
    cout << "\nRequired Jobs: ";
    for (i = 1; i <= dmax; i++)
    {
        cout << jobs[timeslot[i]].id;

        if (i < dmax)
        {
            cout << " --> ";
        }
    }

    // required profit
    maxprofit = 0;
    for (i = 1; i <= dmax; i++)
    {
        maxprofit += jobs[timeslot[i]].profit;
    }
    cout << "\nMax Profit: " << maxprofit << endl;
}
