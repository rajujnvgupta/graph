#include <iostream>
#include<map>
#include<list>

using namespace std;

template<typename T>
class Graph{
    int component = 0;
    map<T,list<T>>adjList;
public:

    Graph(T cp)
    {
        component = cp;
    }
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
        component++;
        dfsHelper(src, visited);

        cout<<endl;
        for(auto node:adjList)
        {
            if(!visited[node.first])
            {
                dfsHelper(node.first, visited);
                component++;
            }
        }
        cout<<endl;
        cout<<"total component = "<<component<<endl;
    }
};

int main()
{
    ///Graph<string> g(0);///in case of string
    Graph<int> g(0);///initializing component to 0
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(7, 6);

    g.printGraph();

    g.dfs(0);

    return 0;
}

