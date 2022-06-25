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

void DFS(node *n)
{
    if (n == NULL) return;

    cout<<n->val<<" ";

    DFS(n->left);
    DFS(n->right);
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

    DFS(a);

    return 0;
}