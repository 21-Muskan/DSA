// B. There are 5 jobs, each with a deadline and associated profit. The Select a subset of jobs that
// maximize the total profit while ensuring that each selected job is completed within its deadline.
// Display the selected jobs with their deadlines.

// Job   Deadline    Profit
// A        2          100
// B        1           19
// C        2           27
// D        1           25
// E        3           15

// Enter the number of jobs: 5
// Enter Job ID, Deadline, and Profit for Job 1: A 2 100
// Enter Job ID, Deadline, and Profit for Job 2: B 1 19
// Enter Job ID, Deadline, and Profit for Job 3: C 2 27
// Enter Job ID, Deadline, and Profit for Job 4: D 1 25
// Enter Job ID, Deadline, and Profit for Job 5: E 3 15

// Selected jobs in optimal sequence:
// Job A with deadline 2 and profit 100
// Job C with deadline 2 and profit 27
// Job E with deadline 3 and profit 15

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

void jobScheduling(Job jobs[], int n)
{

    sort(jobs, jobs + n, compare);

    int result[n];
    bool slot[n];
    memset(slot, 0, sizeof(slot));

    for (int i = 0; i < n; i++)
    {

        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    cout << "Selected jobs in optimal sequence:\n";
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << "Job " << jobs[result[i]].id << " with deadline "
                << jobs[result[i]].deadline << " and profit "
                << jobs[result[i]].profit << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job jobs[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Job ID, Deadline, and Profit for Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    jobScheduling(jobs, n);

    return 0;
}
