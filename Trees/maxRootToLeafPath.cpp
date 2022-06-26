#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    node(int Val)
    {
        left = NULL;
        right = NULL;
        this->val = Val; 
    }

    node *left;
    node *right;
    int val;
};

int DFS(node *n)
{
    if (n == NULL) return INT_MIN;
    if (n->left == NULL && n->right == NULL) return n->val;
    return n->val + max(DFS(n->left), DFS(n->right));
}

int maxRootToLeafPath(node *n)
{
    return DFS(n);
}

int main()
{
    node *n1 = new node(3);
    node *n2 = new node(11);
    node *n3 = new node(4);
    node *n4 = new node(2);
    node *n5 = new node(4);
    node *n6 = new node(1);

    n1->left = n2;
    n1->right = n5;
    n2->left = n3;
    n2->right = n4;
    n5->right = n6;

    cout<<maxRootToLeafPath(n1);
    
    return 0;
}