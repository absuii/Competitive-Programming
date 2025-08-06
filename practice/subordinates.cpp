#include <bits/stdc++.h>
using namespace std;
void dfs(int s, vector<int>& count, vector<vector<int>>& adj){
    for(int u: adj[s]){
        dfs(u, count, adj);
        count[s]+=count[u];
    }
}
int main() {
	int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=2; i<n+1; i++){
        int a; cin>>a;
        adj[a-1].push_back(i-1);
    }
    vector<int> count(n,1);
    dfs(0, count, adj);
    for(int i=0; i<n; i++){
        cout<<count[i]-1<<" ";
    }
}
