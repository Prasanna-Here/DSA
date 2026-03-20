#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start,vector<vector<int>> &adj,int n){
    vector<int> vis(n+1,0);
    queue<int> q;
    q.push(start);
    vis[start]=1;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                vis[neighbour]=1;
                q.push(neighbour);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //not  needed for directed graph
    }
    
    //print adjacency list
    cout<<"adjacency list:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        for(auto it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
    cout<<"BFS Traversal:"<<endl;
    bfs(1,adj,n);
}