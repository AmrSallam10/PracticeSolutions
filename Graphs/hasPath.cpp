#include<bits/stdc++.h>
using namespace std;


// DFS
bool DFSHelper (unordered_map<char, list<char>> &adj, char src, char des, unordered_map<char, bool> &visited)
{
    visited[src] = true;
    if (src == des) return true;

    for (char c : adj[src])
        if (!visited[c] && DFSHelper(adj, c, des, visited) == true)
            return true;
    
    return false;    
}

bool hasPath_DFS (unordered_map<char, list<char>> &adj, char src, char des)
{
    unordered_map<char, bool> visited;
    
    for (auto x : adj)
        visited[x.first] = false;

    bool out = DFSHelper(adj, src, des, visited);
    return out; 
}


// BFS
bool hasPath_BFS (unordered_map<char, list<char>> &adj, char src, char des)
{
    queue<char> q;
    unordered_map<char, bool> visited;
    for (auto x : adj)
        visited[x.first] = false;

    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        src = q.front();
        q.pop();
        if (src == des) return true;

        for (char i : adj[src])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

int main()
{
    unordered_map<char, list<char>> adj;
    
    adj['f'].push_back('g');
    adj['f'].push_back('i');
    adj['g'].push_back('h');
    adj['h'];
    adj['i'].push_back('g');
    adj['i'].push_back('k');
    adj['j'].push_back('i');
    adj['k'];


    char src = 'j', des = 'h';
    // bool out = hasPath_DFS(adj, src, des);
    bool out = hasPath_BFS(adj, src, des);

    cout<< (out? "YES" : "NO");

    return 0;
}