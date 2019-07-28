#include <iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

template<typename T>
class Graph{
    map<T, list<T>>adjlist;

public:
    Graph(){}

    void addEdge(T u, T v, bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void print(){

        for(T i:adjlist)
        {
            cout<<i.first<<" --> ";
            for(T element:i.second)
            {
                cout<<element<<" , ";
            }
        }
    }

    bool isCycleBfs(T src){
        map<T, int>parent;
        map<T, bool>visited;
        queue<T>q;
        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty()){
            T node = q.front();
            q.pop();

            ///iterate over the neighbours of the node leaving parent.

            for(T neighbour:adjlist[node])
            {
                ///if this condition is true then there is a cycle
                if(visited[neighbour] == true && parent[node] != neighbour){
                    return true;
                }

                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
            }
        }
    return false;
    }

};

int main()
{
    Graph<int>g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    ///g.addEdge(2, 3);
    ///g.print();
    if(g.isCycleBfs(0))
        cout<<"there is at least a cycle";
    else
        cout<<"there is not any cycle";
    return 0;
}

