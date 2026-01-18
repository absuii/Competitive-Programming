#include <bits/stdc++.h>
using namespace std;
void dfs(int current, vector<bool>& visited, vector<vector<int>>& adj, vector<pair<int,int>>& dis, int d){
    visited[current] = true;
    dis[current].first = d;
    for(int s: adj[current]){
        if(!visited[s]){
            dfs(s, visited, adj, dis, d+1);
        }
    }
}
int main() {
	int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int,int>> distances(n);
    vector<bool> visited(n);
    for(int i=0; i<n; i++){
        distances[i].second = i;
        distances[i].first = 0;
        visited[i] = false;
    }
    dfs(0, visited,adj,distances, 0);
    sort(distances.begin(), distances.end());
    int one = distances[distances.size()-1].second;
    for(int i=0; i<n; i++){
        distances[i].second = i;
        distances[i].first = 0;
        visited[i] = false;
    }
    dfs(one, visited,adj,distances, 0);
    sort(distances.begin(), distances.end());
    cout<<distances[distances.size()-1].first;
    

}
