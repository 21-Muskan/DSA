// A. Construct an expression tree from postfix expression and perform non- recursive In-order traversals
// abc*+d/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node *lchild;
    Node *rchild;

    Node(char data)
    {
        this->data = data;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
}

Node *CreatingStack(string s)
{
    stack<Node *> k;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            Node *newNode = new Node(s[i]);
            Node *rchild = k.top();
            k.pop();
            Node *lchild = k.top();
            k.pop();
            newNode->rchild = rchild;
            newNode->lchild = lchild;
            k.push(newNode);
            // inorder(newNode);
        }
        else
        {
            k.push(new Node(s[i]));
        }
    }
    return k.top();
}
void expression()
{
    string array;
    cout << "Enter the Postfix Expression:";
    cin >> array;
    Node *root = CreatingStack(array);
    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    expression();
    return 0;
}
