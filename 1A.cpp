// A)Create Binary tree and perform following operations:
// a. Insert
// b. Display
// c. Find Depth of a tree
// d. Display leaf-nodes
// e. Create a copy of a tree

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int data)
    {
        this->data = data;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data for Binary Tree: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for insertion in left of " << data << endl;
    root->lchild = buildTree(root->lchild);
    cout << "Enter data for insertion in right of " << data << endl;
    root->rchild = buildTree(root->rchild);
    return root;
}

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

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    inorder(root->lchild);
    inorder(root->rchild);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lchild);
    inorder(root->rchild);
    cout << root->data << " ";
}

void leaf(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->lchild == NULL && root->rchild == NULL)
    {
        cout << root->data << " ";
    }
    leaf(root->lchild);
    leaf(root->rchild);
}

int finddepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftdepth = finddepth(root->lchild);
    int rightdepth = finddepth(root->rchild);
    return max(leftdepth, rightdepth) + 1;
}

Node* copyTree(Node *root)
{
    if (root == NULL){
        return NULL;
    }
    Node * newnode = new Node(root->data);
    newnode->lchild = copyTree(root->lchild);
    newnode->rchild = copyTree(root->rchild);
    return newnode;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout<<"Showing the copied Tree in inorder :"<<endl;
    inorder(root);
    cout << endl;
    cout<<"Showing the copied Tree in preorder :"<<endl;
    preorder(root);
    cout << endl;
    cout<<"Showing the copied Tree in postorder :"<<endl;
    postorder(root);
    cout << endl;
    cout<<"Showing the leaf nodes:"<<endl;
    leaf(root);
    cout << endl;
    cout<<"Depth of the tree: "<<endl;
    int depth = finddepth(root) -1;
    cout<<depth;
    cout << endl;
    Node * newnode = copyTree(root);
    cout<<"Showing the copied Tree in inorder :"<<endl;
    inorder(newnode);
    cout<<endl;
    
    return 0;
}
