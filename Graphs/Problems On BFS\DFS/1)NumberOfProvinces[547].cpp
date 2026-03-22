#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &mat, vector<int> &vis, int n){
    vis[node] = 1;

    for(int j = 0; j < n; j++){
        if(mat[node][j] == 1 && !vis[j]){
            dfs(j, mat, vis, n);
        }
    }
}

int countProvinces(vector<vector<int>> &mat, int n){
    vector<int> vis(n, 0);
    int provinces = 0;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            provinces++;
            dfs(i, mat, vis, n);
        }
    }

    return provinces;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    // input matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    cout << "Number of Provinces: " << countProvinces(mat, n);

    return 0;
}