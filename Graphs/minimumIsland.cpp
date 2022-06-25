#include<bits/stdc++.h>
using namespace std;

int DFS(vector<vector<char>> &graph, int i, int j, map<pair<int,int>,bool> &visited)
{
    pair<int, int> node = {i,j};
    if(visited[node]) return 0;
    if( i < 0 || i >= graph.size()) return 0;
    if(j < 0 || j >= graph[0].size()) return 0;
    if(graph[i][j] == 'w') return 0;

    int size = 1;
    visited[node] = true;
    size += DFS(graph, i + 1, j, visited);
    size += DFS(graph, i - 1, j, visited);
    size += DFS(graph, i, j + 1, visited);
    size += DFS(graph, i, j - 1, visited);

    return size; 
}

int minimumIsland(vector<vector<char>> &graph)
{
    map<pair<int,int>,bool> visited;
    int size, min=INT_MAX;

    for (int i = 0 ; i < graph.size(); i ++)
        for (int j = 0 ; j < graph[0].size() ; j++)
            visited[{i,j}] = false;

    for (int i = 0 ; i < graph.size(); i ++)
        for (int j = 0 ; j < graph[0].size() ; j++)
        {
            size = DFS(graph, i, j, visited);
            if(size != 0 && size < min)
                min = size;
        }
    return ((min == INT_MAX)? 0 : min);
}

int main()
{
    vector<vector<char>> graph = {{'w', 'l', 'w', 'w', 'l', 'w'},
                                  {'l', 'l', 'w', 'w', 'l', 'w'},
                                  {'w', 'l', 'w', 'w', 'w', 'w'},
                                  {'w', 'w', 'w', 'l', 'l', 'w'},
                                  {'l', 'l', 'w', 'l', 'l', 'w'},
                                  {'w', 'w', 'w', 'w', 'w', 'w'}};
                                    
    int count = minimumIsland(graph);
    cout<<count;
    return 0;
}