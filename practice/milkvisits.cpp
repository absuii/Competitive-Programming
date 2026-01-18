#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> h;
vector<int> g;
void dfs(int parent, int current, vector<bool>& visited, vector<char>& places){
    if(visited[current]) return;
    visited[current] = true;
    int Hamt = 0;
    int Gamt = 0;
    if (places[current] == 'H'){
        Hamt = 1;
    }else{
        Gamt = 1;
    }
    h[current+1] = h[parent+1] + Hamt;
    g[current+1] = g[parent+1] + Gamt;
    for(int s: adj[current]){
        dfs(current, s, visited, places);
    }

}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
	int n, m; cin>>n>>m;
    vector<char> places(n);
    for(int i=0; i<n; i++){
        cin>>places[i];
    }
    h.resize(n+2);
    g.resize(n+2);
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<bool> visited(n);    
    dfs(0, 1, visited, places);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        char t; cin>>t;
        bool ans;
        if(t=='H'){
            if(abs(h[a+1] - h[b+2])>=1){
                ans= true;
            }else{
                ans = false;
            }
        }else{
            if(abs(g[a+1] - g[b+2])>=1){
                ans= true;
            }else{
                ans= false;
            }
        }
        cout<<ans;
    }
}
