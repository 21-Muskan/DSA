// Consider a telephone book database of N clients. Make use of a hash table implementation to quickly
// look up client‘s telephone number. Make use of two collision handling techniques and compare them
// using number of comparisons required to find a set of telephone numbers

// Enter the number of clients: 3
// Enter name and phone number: Alice 12345
// Enter name and phone number: Bob 54321
// Enter name and phone number: Charlie 67890
// Enter name to search: Bob
// Separate Chaining: 54321 found with 1 comparisons.
// Linear Probing: 54321 found with 1 comparisons.

#include <iostream>
#include <list>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

int hashFunction(string key)
{
    int hash = 0;
    for (char ch : key)
        hash += ch;
    return hash % TABLE_SIZE;
}
class HashTableChaining
{
private:
    list<pair<string, string>> *table;

public:
    HashTableChaining()
    {
        table = new list<pair<string, string>>[TABLE_SIZE];
    }

    void insert(string name, string phone)
    {
        int index = hashFunction(name);
        table[index].push_back(make_pair(name, phone));
    }

    string search(string name, int &comparisons)
    {
        int index = hashFunction(name);
        for (auto &entry : table[index])
        {
            comparisons++;
            if (entry.first == name)
                return entry.second;
        }
        return "Not found";
    }

    ~HashTableChaining()
    {
        delete[] table;
    }
};

class HashTableProbing
{
private:
    pair<string, string> *table;
    bool *occupied;

public:
    HashTableProbing()
    {
        table = new pair<string, string>[TABLE_SIZE];
        occupied = new bool[TABLE_SIZE];
        memset(occupied, false, TABLE_SIZE);
    }

    void insert(string name, string phone)
    {
        int index = hashFunction(name);
        int originalIndex = index;
        while (occupied[index])
        {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex)
            {
                cout << "Hash Table is full\n";
                return;
            }
        }
        table[index] = make_pair(name, phone);
        occupied[index] = true;
    }

    string search(string name, int &comparisons)
    {
        int index = hashFunction(name);
        int originalIndex = index;
        while (occupied[index])
        {
            comparisons++;
            if (table[index].first == name)
                return table[index].second;
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex)
                break;
        }
        return "Not found";
    }

    ~HashTableProbing()
    {
        delete[] table;
        delete[] occupied;
    }
};

int main()
{
    HashTableChaining hashChain;
    HashTableProbing hashProbe;

    int N;
    cout << "Enter the number of clients: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name, phone;
        cout << "Enter name and phone number: ";
        cin >> name >> phone;

        hashChain.insert(name, phone);
        hashProbe.insert(name, phone);
    }

    int comparisonsChain = 0, comparisonsProbe = 0;
    string searchName;

    cout << "Enter name to search: ";
    cin >> searchName;

    string resultChain = hashChain.search(searchName, comparisonsChain);
    cout << "Separate Chaining: " << resultChain << " found with " << comparisonsChain << " comparisons.\n";

    string resultProbe = hashProbe.search(searchName, comparisonsProbe);
    cout << "Linear Probing: " << resultProbe << " found with " << comparisonsProbe << " comparisons.\n";

    return 0;
}
