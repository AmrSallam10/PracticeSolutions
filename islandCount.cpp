#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<vector<char>> &graph, int i, int j, map<pair<int,int>,bool> &visited)
{
    pair<int, int> node = {i,j};
    if(visited[node]) return false;
    if( i < 0 || i >= graph.size()) return false;
    if(j < 0 || j >= graph[0].size()) return false;
    if(graph[i][j] == 'w') return false;

    visited[node] = true;
    DFS(graph, i + 1, j, visited);
    DFS(graph, i - 1, j, visited);
    DFS(graph, i, j + 1, visited);
    DFS(graph, i, j - 1, visited);

    return true;
}

int islandCount(vector<vector<char>> &graph)
{
    map<pair<int,int>,bool> visited;
    int count =0;

    for (int i = 0 ; i < graph.size(); i ++)
        for (int j = 0 ; j < graph[0].size() ; j++)
            visited[{i,j}] = false;

    for (int i = 0 ; i < graph.size(); i ++)
        for (int j = 0 ; j < graph[0].size() ; j++)
            if(DFS(graph, i, j, visited)) 
                count++;

    return count;
}

int main()
{
    vector<vector<char>> graph = {{'w', 'l', 'w', 'w', 'l', 'w'},
                                  {'l', 'l', 'w', 'w', 'l', 'w'},
                                  {'w', 'l', 'w', 'w', 'w', 'w'},
                                  {'w', 'w', 'w', 'l', 'l', 'w'},
                                  {'w', 'l', 'w', 'l', 'l', 'w'},
                                  {'w', 'w', 'w', 'w', 'w', 'w'}};
    

    int count = islandCount(graph);
    cout<<count;
    return 0;
}