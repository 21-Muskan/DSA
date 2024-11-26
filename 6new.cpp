#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter the marks of " << n << " students: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    // Using max-heap for finding the maximum mark
    priority_queue<int> maxHeap;
    for (int mark : marks)
    {
        maxHeap.push(mark);
    }

    // Using min-heap for finding the minimum mark
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int mark : marks)
    {
        minHeap.push(mark);
    }

    // Finding maximum and minimum marks
    int maxMark = maxHeap.top();
    int minMark = minHeap.top();

    cout << "Maximum marks: " << maxMark << endl;
    cout << "Minimum marks: " << minMark << endl;

    return 0;
}