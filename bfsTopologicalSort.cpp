#include<iostream>
#include<list>
#include<map>
#include<queue>

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
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {
        for(T i: adjlist)
        {
            cout<<i.first<<" --> ";
            for(T element:i.second)
            {
                cout<<element<<", ";
            }

            cout<<endl;
        }
    }

   void bfsTopologicalSort()
   {
        queue<T>Q;
        map<T, int>inDegree;
        map<T, bool>visited;

        for(auto i:adjlist)
        {
            T node = i.first;
            inDegree[node] = 0;
            visited[node] = false;
        }

        ///init the indegree of all node
        for(auto i:adjlist)
        {
            T u = i.first;

            for(T v: adjlist[u]) ///for(T u:i.second)
            {
                inDegree[v]++;
            }
        }

        ///find out all the nodes with 0 indegree
        for(auto i:adjlist)
        {
            T node = i.first;
            if(inDegree[node] == 0){
                Q.push(node);
            }
        }

        ///start with algorithms
        while(!Q.empty())
        {
            T node = Q.front();
            Q.pop();
            cout<<node<<" --> ";
            for(T neighbour:adjlist[node])
            {
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0)
                    Q.push(neighbour);
            }
        }
   }
};

int main(){

    Graph<string>g;
    g.addEdge("English", "Programming logic", false);
    g.addEdge("Maths", "Programming logic", false);
    g.addEdge("Programming logic", "HTML", false);
    g.addEdge("Programming logic", "Python", false);
    g.addEdge("Programming logic", "Java", false);
    g.addEdge("Programming logic", "Js", false);
    g.addEdge("HTML", "CSS", false);
    g.addEdge("CSS", "Js", false);
    g.addEdge("Js", "Web Dev", false);
    g.addEdge("Java", "Web Dev", false);
    g.addEdge("Python", "Web Dev", false);
    g.bfsTopologicalSort();

    return 0;
}

