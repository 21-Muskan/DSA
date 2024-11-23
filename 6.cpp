// 6. Read the marks obtained by students of second year in an online examination of
// particular subject. Find out maximum and minimum marks obtained in that subject.
// Use heap data structure. Analyse the algorithm.

// Sample Input/output
// Enter the number of students: 5
// Enter marks for student 1: 85
// Enter marks for student 2: 90
// Enter marks for student 3: 78
// Enter marks for student 4: 88
// Enter marks for student 5: 92
// Maximum Marks Obtained: 92
// Minimum Marks Obtained: 78

#include <iostream>
#include <climits>

using namespace std;

#define MAX_STUDENTS 100

void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(arr, n, i);
    }
}

void buildMinHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, n, i);
    }
}
void findMaxMin(int marks[], int n)
{
    int maxHeap[MAX_STUDENTS];
    int minHeap[MAX_STUDENTS];

    for (int i = 0; i < n; i++)
    {
        maxHeap[i] = marks[i];
        minHeap[i] = marks[i];
    }

    buildMaxHeap(maxHeap, n);
    buildMinHeap(minHeap, n);

    int maxMarks = maxHeap[0];

    int minMarks = minHeap[0];

    cout << "Maximum Marks Obtained: " << maxMarks << endl;
    cout << "Minimum Marks Obtained: " << minMarks << endl;
}

int main()
{
    int marks[MAX_STUDENTS];
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter marks for student " << (i + 1) << ": ";
        cin >> marks[i];
    }
    findMaxMin(marks, n);

    return 0;
}
