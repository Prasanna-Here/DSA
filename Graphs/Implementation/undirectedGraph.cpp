#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
}