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

int BFS(node *root)
{
    queue<node*> q;
    q.push(root);
    int sum = 0;

    while(!q.empty())
    {
        node *current = q.front();
        q.pop();

        if(current != NULL)
        {
            sum += current->val;
            q.push(current->left);
            q.push(current->right); 
        }
    }

    return sum;
}

int DFS(node *n)
{
    if(n == NULL) return 0;
    return n->val + DFS(n->left) + DFS(n->right);
}

int treeSum(node *n)
{
    return BFS(n);
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

    cout<<treeSum(n1);
    
    return 0;
}