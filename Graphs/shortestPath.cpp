#include<bits/stdc++.h>
using namespace std;


int BFS(unordered_map <char, list<char>> &adj, char src, char dest, unordered_map<char, bool> &visited)
{
    queue<pair<char, int>> q;
    pair<char, int> current = {src, 0};
    q.push(current);
    visited[src] = true;

    while (!q.empty())
    {
        current = q.front();
        q.pop();
        if (current.first == dest) return current.second;

        for(auto c : adj[current.first])
            if(!visited[c])
            {
                visited[c] = true;
                q.push({c, current.second+1});
            }
    }

    return -1;
}

int shrortestPath(unordered_map <char, list<char>> &adj, char src, char dest)
{
    unordered_map<char, bool> visited;
    for (auto x : adj)
        visited[x.first] = false;

    return BFS(adj, src, dest, visited);
}

void createGraph(vector<vector<char>> graph, unordered_map <char, list<char>> &adj)
{
    for (auto x : graph)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
}

int main()
{
    vector<vector<char>> graph = {{'w','x'}, {'x', 'y'}, {'z', 'y'}, {'z', 'v'}, {'w', 'v'}}; 
    unordered_map <char, list<char>> adj;

    createGraph(graph, adj);
    char src = 'v', dest = 'y';

    int count = shrortestPath(adj, src, dest);
    cout << ((count == -1)? "path not found" : to_string(count));

    return 0;
}