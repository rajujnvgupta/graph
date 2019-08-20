#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int > > >adjlist;

public:
    Graph(){}
    void addEdge(T u, T v, int w, bool bidir=true){
        adjlist[u].push_back(make_pair(v, w));
        if(bidir){
            adjlist[v].push_back(make_pair(u, w));
        }
    }

    void print(){
        for(auto j:adjlist){
            T node = j.first;
            cout<<node<<"--> ";
            for(auto neighbour:adjlist[node]){
                cout<<"( "<< neighbour.first<<" , "<<neighbour.second<<") ,";
            }
            cout<<endl;
        }
    }

    void dijkstra(T src){
        unordered_map<T, int>dist;
        for(auto node:adjlist)
        {
            ///set all distance to infinity
            dist[node.first] = INT_MAX;
        }
        ///make a set to find a out node with the minimum distance
        ///note set sorted according to their first parameter
        set<pair<int, T> >s;

        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty()){

            ///find the pair at the front
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            ///iterate over neighbours/children of the current node
            for(auto childPair:adjlist[node]){
                if(nodeDist + childPair.second < dist[childPair.first]){
                    ///in the set updation of a particular is not possible
                    ///we have to remove the old pair, and insert the new pair to simulation updation

                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end()){
                        s.erase(f);  ///finalized node are removed
                    }

                    ///insert the new pair
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }

        }

        ///lets print distance to all other node from src
        for(auto d:dist){
            cout<<d.first<<" is located to distance of "<<d.second<<endl;
        }
    }
};

int main()
{
/*
    Graph<int>g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    ///g.print();

    g.dijkstra(1);
*/

    Graph<string>g;
    g.addEdge("Amritsir", "Delhi", 1);
    g.addEdge("Amritsir", "Jaipur", 4);
    g.addEdge("Jaipur", "Delhi", 2);
    g.addEdge("Delhi", "Agra", 1);
    g.addEdge("Agra", "Bhopal", 2);
    g.addEdge("Bhopal", "Mumbai", 3);
    g.addEdge("Mumbai","Jaipur" ,8);


    ///g.print();

    
    g.dijkstra("Amritsir");
    return 0;
}

