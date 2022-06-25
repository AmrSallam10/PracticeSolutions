#include<bits/stdc++.h>
using namespace std;


void bfs (int x, int num)
{
    queue<int> q;
    q.push(num);

    while (!q.empty())
    {
        num = q.front();
        q.pop();

        if (num <= x)
        {
            cout<< num <<" ";
            int last = num % 10;

            if (last == 0)
                q.push((num*10) + (last + 1));
            else if (last == 9)
                q.push((num*10) + (last - 1));
            else 
            {
                q.push((num*10) + (last + 1));
                q.push((num*10) + (last - 1));
            }
        }
    }
}

void jumpingNumbers(int x)
{
    cout<< 0 <<" ";

    for (int i = 1 ; i < 10 ; i++)
        bfs(x, i);
}


int main()
{
    jumpingNumbers(40);

    return 0;
}