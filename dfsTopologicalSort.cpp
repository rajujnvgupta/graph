#include <iostream>
#include<map>
#include<list>

using namespace std;

template<typename T>

class Graph{
    map<T, list<T>>adjlist;

public:
    Graph()
    {

    }

    void addEdge(T u, T v, bool bidir)
    {
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void print(){

        for(auto i: adjlist){
            cout<<i.first<<"-->";
        ///i.second is ll
            for(T entry: i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }

    void dfsHelper(T node, map<T, bool>&visited, list<T>&ordering)
    {
        visited[node] = true;
        ///will call dfs on the unvisited neighbour of current node
        for(T neighbour:adjlist[node])
        {
            if(!visited[neighbour]){
                dfsHelper(neighbour, visited, ordering);
            }
        }

        ///add 1 line for TS
        ///At this point all the children of current node have been visited
        ///so we can add current node to the list
        ordering.push_front(node);
    }

    void dfsToplogicalSort(){
        map<T, bool>visited;
        list<T>ordering;

        for(auto i: adjlist){
            ///i is pair (node, list of nodes)
            T node = i.first;
            if(!visited[node]){
                dfsHelper(node, visited, ordering);
            }
        }

        ///print all the element in ordering
        for(T element:ordering){
            cout<<element<<"-->";
        }
    }

};


int main()
{
    Graph<string>g;
    g.addEdge("English", "Programming logic", false);
    g.addEdge("Maths", "Programming logic", false);
    g.addEdge("Programming logic", "HTML", false);
    g.addEdge("Programming logic", "Python", false);
    g.addEdge("Programming logic", "Java", false);
    g.addEdge("Programming logic", "Js", false);
    ///g.addEdge("Python", "Web Dev", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "Js", false);
    g.addEdge("Js", "Web Dev", false);
    g.addEdge("Java", "Web Dev", false);
    g.addEdge("Python", "Web Dev", false);
    g.print();
    cout<<endl;
    g.dfsToplogicalSort();
    return 0;
}

