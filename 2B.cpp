// 2B. Construct an expression tree from postfix expression and perform non- recursive
// In-order, pre-order and post-order traversals

// Enter a postfix expression: ab+cd+*

// Non-recursive In-order traversal: a + b * c + d
// Non-recursive Pre-order traversal: * + a b + c d
// Non-recursive Post-order traversal: a b + c d + *

#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib> // For malloc

using namespace std;

// Structure for a tree node
struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Utility function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct an expression tree from a postfix expression
Node *constructTree(char postfix[])
{
    stack<Node *> st;
    Node *t;
    Node *t1;
    Node *t2;

    // Iterate through the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        // If operand, create a new node and push to stack
        if (!isOperator(postfix[i]))
        {
            t = new Node(postfix[i]);
            st.push(t);
        }
        // If operator, pop two nodes, make them children, and push the result
        else
        {
            t = new Node(postfix[i]);

            // Pop two nodes
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            // Make them children
            t->right = t1;
            t->left = t2;

            // Push the subtree back to stack
            st.push(t);
        }
    }

    // The final node on the stack is the root of the expression tree
    t = st.top();
    st.pop();

    return t;
}

// Non-recursive In-order traversal using a stack
void inOrder(Node *root)
{
    stack<Node *> s;
    Node *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";
        current = current->right;
    }
}

// Non-recursive Pre-order traversal using a stack
void preOrder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *current = s.top();
        s.pop();

        cout << current->data << " ";  

        if (current->right != nullptr)
        {
            s.push(current->right);
        }
        if (current->left != nullptr)
        {
            s.push(current->left);
        }
    }
}

// Non-recursive Post-order traversal using two stacks
void postOrder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != nullptr)
        {
            s1.push(current->left);
        }
        if (current->right != nullptr)
        {
            s1.push(current->right);
        }
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Main function
int main()
{
    char postfix[100];

    cout << "Enter a postfix expression: ";
    cin >> postfix;

    Node *root = constructTree(postfix);

    cout << "\nNon-recursive In-order traversal: ";
    inOrder(root);

    cout << "\nNon-recursive Pre-order traversal: ";
    preOrder(root);

    cout << "\nNon-recursive Post-order traversal: ";
    postOrder(root);

    return 0;
}
