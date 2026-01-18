#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; 
    cin >> n;
    
    vector<ll> adj(n);
    vector<ll> weights(n);
    
    for(ll i = 0; i < n; i++){
        ll a, b; 
        cin >> a >> b;
        adj[i] = a - 1;  // 0-indexed
        weights[i] = b;
    }
    
    vector<bool> visited(n, false);
    vector<bool> in_stack(n, false);
    ll total_min = 0;
    
    for(ll start = 0; start < n; start++){
        if(!visited[start]){
            // Find cycle from this component
            vector<ll> path;
            ll curr = start;
            
            // Traverse until we find a cycle
            while(!visited[curr]){
                visited[curr] = true;
                in_stack[curr] = true;
                path.push_back(curr);
                curr = adj[curr];
            }
            
            // If curr is in current stack, we found a cycle
            if(in_stack[curr]){
                ll min_weight = LLONG_MAX;
                bool in_cycle = false;
                
                for(ll node : path){
                    if(node == curr) in_cycle = true;
                    if(in_cycle){
                        min_weight = min(min_weight, weights[node]);
                    }
                }
                
                total_min += min_weight;
            }
            
            // Clear stack markers
            for(ll node : path){
                in_stack[node] = false;
            }
        }
    }
    
    ll total_weight = accumulate(weights.begin(), weights.end(), 0LL);
    cout << total_weight - total_min << endl;
    
    return 0;
}