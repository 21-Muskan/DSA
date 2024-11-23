// A. Consider a friend’s network on face book social web site. Model it as a graph to
// represent each node as a user and a link to represent the friend relationship between
// them. Store data such as date of birth, number of comments for each user.
// 1. Find who is having maximum friends
// 2. Find who has post maximum and minimum comments
// 3. Find users having birthday in this month
// Hint: (Use adjacency list representation and perform DFS and BFS traversals).

// Sample input and output
// Enter the number of users: 3
// Enter name, date of birth (dd-mm-yyyy), and number of comments for user 1:
// Alice 15-01-2000 10
// Enter name, date of birth (dd-mm-yyyy), and number of comments for user 2:
// Bob 22-02-1999 5
// Enter name, date of birth (dd-mm-yyyy), and number of comments for user 3:
// Charlie 07-10-2001 15
// Enter the number of friendships: 2
// Enter the indices (0-based) of two friends:
// 0 1
// Enter the indices (0-based) of two friends:
// 1 2
// Users:
// 0. Alice
// 1. Bob
// 2. Charlie
// User with maximum friends: Bob with 2 friends.
// User with maximum comments: Charlie with 15 comments.
// User with minimum comments: Bob with 5 comments.
// Enter the current month (MM): 10
// Users with birthdays in 10:
// Charlie
// Enter the index (0-based) of the user to start BFS and DFS: 0
// BFS Traversal: Alice Bob Charlie
// DFS Traversal: Alice Bob Charlie

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX_USERS 100  // Maximum number of users
#define MAX_FRIENDS 50 // Maximum number of friends per user

// Structure to represent each user
struct User
{
    string name;
    string dob; // Date of Birth in the format "dd-mm-yyyy"
    int num_comments;
    int friends[MAX_FRIENDS]; // Adjacency list to store friends (edges)
    int num_friends;
};

// Graph class to represent the friend network
class FriendNetwork
{
private:
    User users[MAX_USERS]; // Array to store user data
    int num_users;         // Total number of users

public:
    // Constructor to initialize the number of users
    FriendNetwork() : num_users(0) {}

    // Function to add a user
    void addUser(string name, string dob, int comments)
    {
        users[num_users].name = name;
        users[num_users].dob = dob;
        users[num_users].num_comments = comments;
        users[num_users].num_friends = 0;
        num_users++;
    }

    // Function to add a friendship link between two users
    void addFriendship(int u, int v)
    {
        if (users[u].num_friends < MAX_FRIENDS && users[v].num_friends < MAX_FRIENDS)
        {
            users[u].friends[users[u].num_friends++] = v;
            users[v].friends[users[v].num_friends++] = u;
        }
    }

    // Function to find the user with the maximum friends
    void findMaxFriends()
    {
        int max_friends = -1;
        int max_user = -1;
        for (int i = 0; i < num_users; i++)
        {
            if (users[i].num_friends > max_friends)
            {
                max_friends = users[i].num_friends;
                max_user = i;
            }
        }
        if (max_user != -1)
        {
            cout << "User with maximum friends: " << users[max_user].name
                << " with " << max_friends << " friends.\n";
        }
    }

    // Function to find the user with the maximum and minimum comments
    void findMaxMinComments()
    {
        int max_comments = -1, min_comments = -1;
        int max_user = -1, min_user = -1;

        for (int i = 0; i < num_users; i++)
        {
            if (users[i].num_comments > max_comments)
            {
                max_comments = users[i].num_comments;
                max_user = i;
            }
            if (users[i].num_comments < min_comments)
            {
                min_comments = users[i].num_comments;
                min_user = i;
            }
        }

        if (max_user != -1)
        {
            cout << "User with maximum comments: " << users[max_user].name
                << " with " << max_comments << " comments.\n";
        }
        if (min_user != -1)
        {
            cout << "User with minimum comments: " << users[min_user].name
                << " with " << min_comments << " comments.\n";
        }
    }

    // Function to find users with a birthday in the current month
    void findUsersWithBirthday(string current_month)
    {
        cout << "Users with birthdays in " << current_month << ":\n";
        for (int i = 0; i < num_users; i++)
        {
            string user_month = users[i].dob.substr(3, 2);
            if (user_month == current_month)
            {
                cout << users[i].name << "\n";
            }
        }
    }

    // BFS traversal from a given node
    void bfs(int start)
    {
        bool visited[MAX_USERS] = {false};
        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (!q.empty())
        {
            int user = q.front();
            q.pop();
            cout << users[user].name << " ";

            for (int i = 0; i < users[user].num_friends; i++)
            {
                int friend_user = users[user].friends[i];
                if (!visited[friend_user])
                {
                    q.push(friend_user);
                    visited[friend_user] = true;
                }
            }
        }
        cout << endl;
    }

    // DFS traversal helper function
    void dfsUtil(int user, bool visited[])
    {
        visited[user] = true;
        cout << users[user].name << " ";

        for (int i = 0; i < users[user].num_friends; i++)
        {
            int friend_user = users[user].friends[i];
            if (!visited[friend_user])
            {
                dfsUtil(friend_user, visited);
            }
        }
    }

    // DFS traversal from a given node
    void dfs(int start)
    {
        bool visited[MAX_USERS] = {false};
        cout << "DFS Traversal: ";
        dfsUtil(start, visited);
        cout << endl;
    }

    // Function to print user list
    void printUsers()
    {
        cout << "Users:\n";
        for (int i = 0; i < num_users; i++)
        {
            cout << i << ". " << users[i].name << "\n";
        }
    }
};

int main()
{
    FriendNetwork network;
    int num_users, num_friendships;

    // Input for users
    cout << "Enter the number of users: ";
    cin >> num_users;
    for (int i = 0; i < num_users; i++)
    {
        string name, dob;
        int comments;
        cout << "Enter name, date of birth (dd-mm-yyyy), and number of comments for user " << i + 1 << ":\n";
        cin >> name >> dob >> comments;
        network.addUser(name, dob, comments);
    }

    // Input for friendships
    cout << "Enter the number of friendships: ";
    cin >> num_friendships;
    for (int i = 0; i < num_friendships; i++)
    {
        int u, v;
        cout << "Enter the indices (0-based) of two friends:\n";
        cin >> u >> v;
        network.addFriendship(u, v);
    }

    // Print user list
    network.printUsers();

    // Perform tasks
    network.findMaxFriends();
    network.findMaxMinComments();

    // Find users with birthdays in the current month
    string current_month;
    cout << "Enter the current month (MM): ";
    cin >> current_month;
    network.findUsersWithBirthday(current_month);

    // Perform BFS and DFS traversals
    int start_user;
    cout << "Enter the index (0-based) of the user to start BFS and DFS: ";
    cin >> start_user;
    network.bfs(start_user);
    network.dfs(start_user);

    return 0;
}
