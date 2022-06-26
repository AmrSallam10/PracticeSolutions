#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        node(char Val)
        {
            left = NULL;
            right = NULL;   
            this->val = Val;
        }

        node *left;
        node *right;
        char val;
};

bool BFS(node *n, char val)
{
    queue<node*> q;
    q.push(n);

    while (!q.empty())
    {
        node* current = q.front();
        q.pop();
        if(current->val == val) return true;
        if(current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
    return false;
}

bool DFS(node *n, char val)
{
    if (n == NULL) return false;
    if (n->val == val) return true;

    return (DFS(n->left, val) || DFS(n->right, val));
}

int main()
{
    node *a = new node('a');
    node *b = new node('b');
    node *c = new node('c');
    node *d = new node('d');
    node *e = new node('e');
    node *f = new node('f');

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    char val = 'g';
    // cout << (DFS(a, val)? "EXISTS" : "NOT EXSIST");
    cout << (BFS(a, val)? "EXISTS" : "NOT EXSIST");

    return 0;
}