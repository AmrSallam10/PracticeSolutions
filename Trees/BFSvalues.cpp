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

void BFS(node *n)
{
    queue<node*> q;
    q.push(n);

    while (!q.empty())
    {
        node* current = q.front();
        q.pop();
        cout<<current->val << " ";

        if(current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
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

    BFS(a);

    return 0;
}