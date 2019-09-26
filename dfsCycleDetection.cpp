#include <bits/stdc++.h>
#include<list>
using namespace std;


class Graph{
    int V;

public:

    list<int>*adjList;
    Graph(int v){
        
        V = v;
        adjList = new list<int>[V];
    }
    
    void addEdge(int u, int v){
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    void print(){
        
        for(int i = 0; i < V; i++){
            
            cout<<i<<" -> ";
            for(int neighbour:adjList[i]){
                cout<<neighbour<<" ,";
            }
            
            cout<<endl;
        }
    }
    
    
    
    bool dfsHelper(int node, vector<bool>&visited, int parent){
        
        visited[node] = 1;
        
        for(int neighbour:adjList[node]){
            
            if(!visited[neighbour]){
                
                    bool isCycle = dfsHelper(neighbour, visited, node);
                    if(isCycle){
                        return true;
                    }
            }
            
            ///this condition meaning there is more path to reach this vertex;
            ///it means there is cycle;
            else if(neighbour != parent){
                
                return true;
            }
        }
        return false;
    }
    
    bool dfs(){
        
        vector<bool>visited(V, 0);
        
        for(int i = 0; i < V; i++){
            
            if(!visited[i]){

                bool isCycle = dfsHelper(i, visited, i);
                
                if(isCycle){
                    
                    return true;
                }
            }
        }
        
        return false;
    }
};


int main() {
	// your code goes here
	
    int vertex, edge;
    cin>>vertex>>edge;
    
    Graph g(vertex);
    
    for(int i = 0; i< edge; i++){
        
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }
    
	///g.print();
	
	if(g.dfs()){
	    
	    cout<<"cycle is present"<<endl;
	   
	}
	else {
	    cout<<"cycle is not present"<<endl;
	}
	
	return 0;
}

