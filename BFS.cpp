#include<bits/stdc++.h>
using namespace std;


// iterative version
void BFS(vector<list<int>> &adjList, int s)
{
    bool *visited = new bool [adjList.size()];
    queue<int> q;
    list<int>::iterator it;

    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        s = q.front();
        cout<<s<<" ";
        q.pop();

        for(it = adjList[s].begin(); it != adjList[s].end() ; it++)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

int main()
{
    vector<list<int>> adjList(5);
    adjList[0].push_back(1);
    adjList[0].push_back(4);

    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);

    adjList[2].push_back(1);
    adjList[2].push_back(3);

    adjList[3].push_back(1);
    adjList[3].push_back(2);
    adjList[3].push_back(4);

    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[4].push_back(3);

    BFS(adjList, 0);

    return 0;
}