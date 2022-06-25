#include<bits/stdc++.h>
using namespace std;


// version 1

// void DFS (unordered_map <int, list<int>> &adj, int src, int &count, unordered_map<int, bool> &visited)
// {
//     visited[src] = true;
//     count++;

//     for (int x : adj[src])
//         if (!visited[x])
//             DFS(adj, x, count, visited);
// }


// int largestComponent(unordered_map <int, list<int>> &adj)
// {
//     unordered_map<int, bool> visited;
//     vector<int> c;
//     int count;

//     for (auto x : adj)
//         if (!visited[x.first])
//         {
//             count = 0;
//             DFS(adj, x.first, count, visited);
//             c.push_back(count);
//         }

//     return *max_element(c.begin(), c.end());
// }


// version 2

int DFS (unordered_map <int, list<int>> &adj, int src, unordered_map<int, bool> &visited)
{
    if (visited[src])
        return 0;

    visited[src] = true;
    int size = 1;
    for (int x : adj[src])
        size += DFS(adj, x, visited);

    return size;
}

int largestComponent(unordered_map <int, list<int>> &adj)
{
    unordered_map<int, bool> visited;
    vector<int> c;

    for (auto x : adj)
        if (!visited[x.first])
        {
            // DFS(adj, x.first, count, visited);
            c.push_back(DFS(adj, x.first, visited));
        }

    return *max_element(c.begin(), c.end());
}

int main()
{
    unordered_map <int, list<int>> adj;
    adj[0].push_back(8);
    adj[0].push_back(1);
    adj[0].push_back(5);
    adj[1].push_back(0);
    adj[5].push_back(0);
    adj[5].push_back(8);
    adj[8].push_back(0);
    adj[8].push_back(5);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(2);

    int largestSize = largestComponent(adj);
    cout << largestSize;

    return 0;
}