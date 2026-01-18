#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dist(pair<ll,ll> one, pair<ll,ll> two){
    return (one.second - two.second) *(one.second - two.second) + (one.first-two.first) *(one.first-two.first);
}
void dfs(ll current, const vector<vector<ll>>& adj, vector<bool>& visited, ll mid) {
    visited[current] = true;
    for (ll neighbor = 0; neighbor < adj.size(); neighbor++) {
        if (!visited[neighbor] && adj[current][neighbor] <= mid) {
            dfs(neighbor, adj, visited, mid);
        }
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
	ll n; cin>>n;
    vector<pair<ll,ll>> positions(n);
    for(ll i=0; i<n; i++){
        cin>>positions[i].first>>positions[i].second;
    }
    vector<vector<ll>> adj(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            adj[i][j] = dist(positions[i], positions[j]);
       }
    }
    ll low = 0; ll high = 2e10;
    ll mid = (high-low)/2 + low;
    ll c = 100;
    while(c--){
        mid = (high-low)/2+low;
        vector<bool> visited(n);
        dfs(0, adj, visited, mid);
        bool works = true;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                works = false;
            }
        }
        if(works){

            high = mid-1;

        }else{
            low = mid+1;
        }
    }
    cout<<mid;
}
