#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

class Edge{
    
    public:
    
    int src;
    int dest;
    int weight;
};

class Graph{
    
    int V, E;
    public:
    
        Edge *edge;
    Graph(int v, int e){
        
        V = v;
        E = e;
        edge = new Edge[E];
    }
    
    void addEdge(int u, int v, int w, int counter){
        
        edge[counter].src = u;
        edge[counter].dest = v;
        edge[counter].weight = w;
    }
    
    
    
    void bellManFord(int src){
        
        int *distance = new int[V];
        
        for(int i = 0; i < V; i++){
            
            if(src == i){
                
                distance[i] = 0;
            }
            else{
                
                distance[i] = inf;
            }
        }
            
        for(int i = 0; i < V-1; i++){
            
            for(int j = 0; j < E; j++){
                
                int src = edge[j].src;
                int dest = edge[j].dest;
                int weight = edge[j].weight;
                
                if(distance[dest] > distance[src] + weight){
                    
                    distance[dest] = distance[src] + weight;
                }
            }
        }
        
        ///for negative cycle detection
        for(int j = 0; j < E; j++){
                
            int src = edge[j].src;
            int dest = edge[j].dest;
            int weight = edge[j].weight;
                
            if(distance[dest] > distance[src] + weight){
                   
                   cout<<"-ve cycle is detected"<<endl; 
                ///distance[dest] = distance[src] + weight
            }
        }
        
        
        /// distance[i] store minimum weight to reach i index
        for(int i = 0; i < V; i++){
            
            cout<<"distance of "<<i<<" is "<<distance[i]<<endl;
        }
    }
};


int main() {
    
    int v, e;
    cin>>v>>e;
    Graph g(v, e);
    
    for(int i = 0; i < e; i++){
        
        int u, v, w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w, i); //i work as counter
    }
    
    int source = 0;
    g.bellManFord(source);
	// your code goes here
	
	return 0;
}

