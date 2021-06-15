#include <iostream>
#include<list>
#include<climits>
using namespace std;

class Graph{
    list<pair<int, int>> *adj;
    int v;
public:
    Graph(int v){
        this->v = v;
        adj = new list<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int findMinVertex(int *weight, int *visited, int v){
        int minVertex = -1;
        for(int i = 0; i < v; i++){
            if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
                minVertex = i;
            }
        }

        return minVertex;
    }

    void Prims(int v){
        int *visited = new int[v];
        int *parent = new int[v];
        int *weight = new int[v];

        for(int i = 0; i < v; i++)
        {
            weight[i] = INT_MAX;
           /// parent[i] = i;
            visited[i] = false;
        }

        weight[0] = 0;
        parent[0] = -1; /// why this why not parent[0] = 0;
        for(int i = 0; i < v; i++){
            int minVertex = findMinVertex(weight, visited, v);///extracting vertex with minimum weight that has not visited
            visited[minVertex] = true;
            for(auto neighbour:adj[minVertex]){
                if(!visited[neighbour.first] && (weight[neighbour.first] > neighbour.second)){
                    weight[neighbour.first] = neighbour.second;
                    parent[neighbour.first] = minVertex;
                }
            }
        }
        for(int i = 1; i < v; i++){
            cout<<i <<" "<<parent[i]<<" "<<weight[i]<<endl;
        }

    }
};


int main() {
    int n, e;
    cin>>n>>e;
    Graph g(n);
    /*
    7
    8
    0 3 2
    0 1 6
    1 2 4
    2 3 8
    3 4 3
    4 6 4
    4 5 1
    6 5 2
    */

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w);
    }
    g.Prims(n);

    return 0;
}

