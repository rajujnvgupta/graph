#include <iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{

    list<int>*adjList;
    int V;
public:
    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v, bool bidir=true)
    {
        adjList[v].push_back(u);
        if(bidir)
        {
            adjList[u].push_back(v);
        }
    }

    void printEdge()
    {
        for(int i = 0; i < V; i++)
        {
            cout<<i<<"-> ";
            for(auto element:adjList[i])
            {
                cout<<element<<", ";
            }
            cout<<endl;
        }
    }

    void bfs(int src)
    {
        queue<int>q;
        bool *visited = new bool[V+1]{0};
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int neighbour:adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);

    ///g.printEdge();

    g.bfs(0);
    return 0;
}

