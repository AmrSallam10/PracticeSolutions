#include<bits/stdc++.h>
using namespace std;


// DFS
void topologicalSortHelper(vector<list<int>> &adj, int s, bool visited[], stack<int> &st)
{
    visited[s] = true;
    list<int>::iterator it;

    for (it = adj[s].begin(); it != adj[s].end(); it++)
        if(!visited[*it])
            topologicalSortHelper(adj, *it, visited, st);

    st.push(s);
}

void topologicalSort(vector<list<int>> &adj, int s)
{
    stack<int> st;
    bool *visited = new bool[adj.size()];

    topologicalSortHelper(adj, s, visited, st);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}


int main()
{
    vector<list<int>> adjList(5);

    adjList[0].push_back(1);
    adjList[0].push_back(4);

    adjList[1].push_back(2);
    adjList[1].push_back(3);

    adjList[4].push_back(3);

    topologicalSort(adjList, 0);

    return 0;
}