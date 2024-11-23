// 9. A. Given a set of items with weights and values, and a knapsack capacity, find the maximum total
// value that can be obtained by selecting fractions of items using the Greedy strategy.

// Enter the number of items: 3
// Enter weight and value for item 1: 10 60
// Enter weight and value for item 2: 20 100
// Enter weight and value for item 3: 30 120
// Enter knapsack capacity: 50
// Maximum total value obtained: 240

#include <iostream>
#include <algorithm>
using namespace std; 

struct Item
{
    int weight;
    int value;
};
double valuePerWeight(Item item)
{
    return (double)item.value / item.weight;
}
bool comparator(Item a, Item b)
{
    return valuePerWeight(a) > valuePerWeight(b);
}

double fractionalKnapsack(Item items[], int n, int capacity)
{
    sort(items, items + n, comparator);

    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else
        {
            int remainingCapacity = capacity - currentWeight;
            totalValue += valuePerWeight(items[i]) * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    double maxValue = fractionalKnapsack(items, n, capacity);

    cout << "Maximum total value obtained: " << maxValue << endl;

    return 0;
}
