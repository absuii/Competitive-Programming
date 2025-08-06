#include <bits/stdc++.h>
using namespace std;
bool cont; int fin;
void dfs(vector<bool>& visted, vector<int>& adj, int current){
    if(visted[current]){
        cont = false;
        fin = current;
        return;
    }
    visted[current]=true;
    if(cont){
        dfs(visted,adj,adj[current]);
    }
}
int main() {
	int n; cin>>n;
    vector<int> adj(n);
    for(int i=0; i<n; i++){
        cin>>adj[i];
        adj[i]--;
    }
    for(int i=0; i<n; i++){
        vector<bool> visited(n);
        cont = true;
        fin = i;
        dfs(visited,adj,i);
        cout<<fin+1;
        if(i!=n-1){
            cout<<" ";
        }
    }
}
