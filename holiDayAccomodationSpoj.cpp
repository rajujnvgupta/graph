#include <bits/stdc++.h>

using namespace std;



class Graph{
    list<pair<int, int>>*adjlist;
    int V;
public:

    Graph(int v){
        V = v;
        adjlist = new list<pair<int , int>>[V];
    }

    void addEdge(int u, int v, int cost, bool bidir=true){
        adjlist[u].push_back(make_pair(v, cost));
        if(bidir){
            adjlist[v].push_back(make_pair(u, cost));
        }
    }

    ///return size of the subtree
    int dfsHelper(int node, bool *visited, int *cnt, int &ans){

        visited[node] = true;
        cnt[node] = 1;

        ///you to recursively find out the size of its children/neighbours
        for(auto neighbour:adjlist[node]){

            int v = neighbour.first;
            if(!visited[v]){
                cnt[node] += dfsHelper(v, visited, cnt, ans);
                ///calculation cast from cnt
                int s = cnt[v];///why not node
                int edgeCost = neighbour.second;
                ans += 2 * min(s, V-s)*edgeCost;
            }
        }
        return cnt[node];
    }

    int dfs(){

        bool *visited = new bool[V]{0};
        ///below array store subtree count in graph.
        int *cnt = new int[V]{0};

        int ans = 0;
        dfsHelper(0, visited, cnt, ans);
        ///printing count array
        for(int i=0; i < V; i++){
            cout<<cnt[i]<<" ";
        }
        return ans;
    }
};

int main()
{
    Graph g(4); /// no of node = 4;
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(3, 2, 2);
    ///g.addEdge(2, 4, 4);
    cout<<g.dfs()<<endl;
    return 0;
}

