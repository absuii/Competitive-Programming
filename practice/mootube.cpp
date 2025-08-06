#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> adj;
vector<vector<ll>> weights;
vector<bool> visited;
ll c = 0;
void dfs(ll current, ll minimum){
    if(visited[current]) return;
     visited[current] = true;
    for(ll i:adj[current]){
        if(!visited[i] && weights[current][i] >= minimum){
            c++;
            dfs(i, minimum);
        }
    }
}
int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
	ll n, q; cin>>n>>q;
    adj.resize(n);
    visited.resize(n);
    weights.resize(n);
    for(ll i=0; i<n;i++){
        for(ll j=0; j<n; j++){
            weights[i].push_back(0);
        }
    }
    for(ll i=0; i<n-1; i++){
        ll a, b; cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
        ll r; cin>>r;
        weights[a-1][b-1] = r;
        weights[b-1][a-1] = r;
    }
    for(ll i=0; i<q; i++){
        ll a, b; cin>>a>>b;
        c = 0;
        for(int i=0; i<n; i++){
            visited[i] = false;
        }
        dfs(b-1, a);
        cout<<c<<endl;
    }



}
