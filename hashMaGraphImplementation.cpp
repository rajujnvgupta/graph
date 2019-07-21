#include <iostream>
#include<list>
#include<map>

using namespace std;

template<typename T>

class Graph{
    ///for unweighted graph
    map<T, list<T>>adjList;

    ///for weighted graph
    ///map<T, list<pair<T, int>>adjList;

 public:
    Graph()
    {
        ///no need to initialize any thing
    }

    ///assuming bidir graphs

    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);

        }
    }

    void printAdjlist()
    {
        ///iterate over maps = use a for each loop
        for(auto row:adjList)
        {
            T key = row.first;
            cout<<key<<"->";
            for(T element:row.second)
            {
                cout<<element<<",";
            }
            cout<<endl;
        }
    }

};

int main()
{

    Graph<string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Delhi","Agra");
    g.addEdge("Amritsar", "Siachen");

    g.printAdjlist();

    return 0;
}

