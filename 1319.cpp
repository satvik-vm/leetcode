#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> adj[], vector<bool>& visited, int i){
    visited[i] = true;
    for(int j : adj[i]){
        if(!visited[j]){
            dfs(adj, visited, j);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];
    vector<bool> visited(n, false);
    int size = connections.size();
    if(size < n-1)  return -1;
    for(int i = 0;i < size;i++){
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    int ans = 0;
    for(int i = 0;i < n; i++){
        if(!visited[i]){
            dfs(adj, visited, i);
            ans++;
        }
    }
    return --ans;
}

int main() {
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}, {0, 3}};
    cout << makeConnected(n, connections) << endl;
    return 0;
}