// 1B. Implement binary search tree and perform following operations:
// a. Insert b. Delete c. Display d. Search e. BFS (Level wise print)

// Binary Search Tree Operations:
// 1. Insert
// 2. Delete
// 3. Display (In-order Traversal)
// 4. Search
// 5. BFS (Level-wise print)
// 6. Exit
// Enter your choice: 1
// Enter the value to insert: 50

// Binary Search Tree Operations:
// 1. Insert
// 2. Delete
// 3. Display (In-order Traversal)
// 4. Search
// 5. BFS (Level-wise print)
// 6. Exit
// Enter your choice: 1
// Enter the value to insert: 30

// Binary Search Tree Operations:
// 1. Insert
// 2. Delete
// 3. Display (In-order Traversal)
// 4. Search
// 5. BFS (Level-wise print)
// 6. Exit
// Enter your choice: 3
// In-order traversal: 30 50

// Binary Search Tree Operations:
// 1. Insert
// 2. Delete
// 3. Display (In-order Traversal)
// 4. Search
// 5. BFS (Level-wise print)
// 6. Exit
// Enter your choice: 5
// BFS (Level-wise print): 50 30

#include <iostream>
#include <queue> // For BFS (Level-wise print)
using namespace std;

// Node structure for Binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Insert a node into the BST
Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Find the minimum value node in a BST
Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// Delete a node from the BST
Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node to be deleted found
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children, find the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// In-order traversal (Display)
void inOrderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Search for a node in the BST
bool search(Node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    if (key == root->data)
    {
        return true;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

// Breadth-First Search (Level-wise print)
void BFS(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Main function
int main()
{
    Node *root = nullptr;
    int choice, data;

    while (true)
    {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display (In-order Traversal)\n";
        cout << "4. Search\n";
        cout << "5. BFS (Level-wise print)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> data;
            root = insert(root, data);
            break;

        case 2:
            cout << "Enter the value to delete: ";
            cin >> data;
            root = deleteNode(root, data);
            break;

        case 3:
            cout << "In-order traversal: ";
            inOrderTraversal(root);
            cout << endl;
            break;
        case 4:
            cout << "Enter the value to search: ";
            cin >> data;
            if (search(root, data))
            {
                cout << "Value found in the BST.\n";
            }
            else
            {
                cout << "Value not found in the BST.\n";
            }
            break;

        case 5:
            cout << "BFS (Level-wise print): ";
            BFS(root);
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
