#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sum = 0;
void dfs(vector<vector<ll>>& adj, vector<ll>& weights, vector<bool>& visited, ll current){
    if(visited[current]) return;
    visited[current] = true;
    ll ans = 0;
    for(ll s: adj[current]){
        if(!visited[s]){

        ans =max(ans, weights[s]);
        }
    }
    sum+=ans;
    for(ll s: adj[current]){
        dfs(adj,weights,visited,s);
    }
}
int main() {
	ll n; cin>>n;
    vector<ll> succ(n);
    vector<vector<ll>> prev(n);
    vector<ll> weights(n);
    for(ll i=0; i<n; i++){
        cin>>succ[i]; 
        succ[i]--;
        prev[succ[i]].push_back(i);
        cin>>weights[i];
    }
    vector<bool> visited(n);
    for(ll i=0; i<n; i++){
        dfs(prev, weights, visited,i);
    }
    cout<<sum;

     
}
