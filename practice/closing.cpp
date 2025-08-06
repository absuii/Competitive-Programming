#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
map<int, bool> closed;
vector<bool> visited;
int counted;
void resetVisited(){
    counted = 0;
    for(int i=0; i<visited.size(); i++){
        visited[i] = false;
    }
}
void dfs(int node){
    if(visited[node] || closed[node]){return;}
    counted++;
    visited[node] = true;
    for(int s: adj[node]){
        if(!closed[s]){dfs(s);}
    }
}
int current = 0;
int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
	int n, m; cin>>n>>m;
    adj.resize(n);
    visited.resize(n);
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for(int i=0; i<n; i++){
        resetVisited();
        while(closed[current] == true){current++;}
        dfs(current);
        if(counted == n -i){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        int close; cin>>close; close--;
        closed[close] = true;
    }
}
