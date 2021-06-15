#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{
    map<T, list<T>>adjlist;
    T V;
public:

    Graph(T v){
        V = v;
    }

    void addEdge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    bool isBipartile(T src){
        queue<T>q;
        q.push(src);
        T *colors = new T[V];

        for(int i = 0; i < V; i++)
        {
            colors[i] = -1;
        }
        colors[src] = 0;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto neighbour:adjlist[node]){
                if(colors[neighbour]==-1)
                {
                    colors[neighbour] = 1 - colors[node];
                    q.push(neighbour);
                }

                else if(colors[neighbour] == colors[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

};

int main()
{
    Graph<int>g(4);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(0, 1);

    if(g.isBipartile(0))
        cout<<"yes, it is";

    else
        cout<<"no, it is not";

    return 0;
}

