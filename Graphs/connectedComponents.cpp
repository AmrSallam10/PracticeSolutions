#include<bits/stdc++.h>
using namespace std;

void BFS(unordered_map <int, list<int>> &adj, int src, unordered_map<int, bool> &visited)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        src = q.front();
        q.pop();

        for (int x : adj[src])
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
    }
}

void DFS (unordered_map <int, list<int>> &adj, int src, unordered_map<int, bool> &visited)
{
    visited[src] = true;
    for (int c : adj[src])
        if(!visited[c])
            DFS(adj, c, visited);
}

// using BFS and DFS
int connectedComponents(unordered_map <int, list<int>> &adj)
{
    unordered_map<int, bool> visited;
    int count = 0;
    for (auto x : adj)
        visited[x.first] = false;

    for (auto x : adj)
        if(!visited[x.first] && ++count)
            DFS(adj, x.first, visited);
            // BFS(adj, x.first, visited);

    return count;
}


int main()
{
    unordered_map <int, list<int>> adj;
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[4].push_back(6);
    adj[6].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(5);
    adj[8].push_back(6);
    adj[6].push_back(8);
    adj[7].push_back(6);
    adj[6].push_back(7);
    adj[3];

    int count = connectedComponents(adj);
    
    cout << count;

    return 0;
}