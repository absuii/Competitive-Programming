#include <bits/stdc++.h>
#include <cctype>
using namespace std;
double e = 0;
void dfs(int current, vector<vector<int>>& adj, vector<bool>& visited, int dis, double prob){
    if(visited[current]){
        return;
    }
    visited[current] = true;
    int c=0;
    for(int s: adj[current]){
        if(!visited[s]){
            c++;
        }
    }
    for(int s: adj[current]){
        if(!visited[s]){
            dfs(s, adj, visited, dis+1,prob/double(c));
        }
    }

    if(c==0){
        e+=(double(dis) * prob);
    }
}
int main() {
	int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a,b; cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool>visited(n);
    dfs(0, adj, visited, 0, 1.0);
    cout << fixed << setprecision(7) << e << '\n';
}
