#include<bits/stdc++.h>
using namespace std;

// iterative version
void DFS_iter (vector<list<int>> &adj, int s)
{
    bool *visited = new bool [adj.size()];
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while (!st.empty())
    {
        s = st.top();
        st.pop();
        cout<<s<<" ";
        list<int>::iterator it;

        for (it = adj[s].begin() ; it != adj[s].end() ; it++)
            if (!visited[*it])
            {
                visited[*it] = true;
                st.push(*it);
            }
    }
}


// recursive version
void DFSHelper(vector<list<int>> &adj, int s, bool visited[])
{
    visited[s] = true;
    cout<<s<<" ";

    list<int>::iterator it;

    for (it = adj[s].begin(); it != adj[s].end(); it++)
        if(!visited[*it])
            DFSHelper(adj, *it, visited);
}

void DFS_re (vector<list<int>> &adj, int s)
{
    bool *visited = new bool [adj.size()];
    DFSHelper(adj, s, visited);
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

    DFS_iter(adjList, 0);
    // DFS_re(adjList, 0);

    return 0;
}