#include <iostream>
#include<map>
#include<list>

using namespace std;

template<typename T>
class Graph{

    map<T,list<T>>adjList;
public:

    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(auto node:adjList)
        {
            cout<<node.first<<" -> ";

            ///
            for(T element:node.second)
            {
                cout<<element<<", ";
            }
            cout<<endl;
        }
    }

    void dfsHelper(T node, map<T, bool>&visited)
    {
        ///whenever to come to a node mark it visited
        visited[node] = true;
        cout<<node<<" ";
        ///try to find out a node which is neighbour of current node and not yet visited
        for(T neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool>visited;
        dfsHelper(src, visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.printGraph();

    g.dfs(0);

    return 0;
}

