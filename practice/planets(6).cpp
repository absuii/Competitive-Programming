#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> adj(n);
    
    for(int i = 0; i < n; i++){
        cin >> adj[i];
        adj[i]--; // Convert to 0-indexed
    }
    
    vector<int> dist(n, -1);
    vector<bool> visited(n, false);
    
    for(int start = 0; start < n; start++){
        if(visited[start]) continue;
        
        // Find all nodes in this component
        vector<int> path;
        int curr = start;
        
        // Follow the path until we find a cycle
        while(!visited[curr]){
            visited[curr] = true;
            path.push_back(curr);
            curr = adj[curr];
        }
        
        // Find where the cycle starts in our path
        int cycle_start_idx = -1;
        for(int i = 0; i < path.size(); i++){
            if(path[i] == curr){
                cycle_start_idx = i;
                break;
            }
        }
        
        if(cycle_start_idx == -1){
            // curr is not in our path, so we hit a previously processed cycle
            // Find the distance to curr
            for(int i = path.size() - 1; i >= 0; i--){
                dist[path[i]] = dist[curr] + (path.size() - i);
            }
        } else {
            // We found a cycle in our path
            int cycle_len = path.size() - cycle_start_idx;
            
            // Set distances for cycle nodes
            for(int i = cycle_start_idx; i < path.size(); i++){
                dist[path[i]] = cycle_len;
            }
            
            // Set distances for nodes leading to cycle
            for(int i = cycle_start_idx - 1; i >= 0; i--){
                dist[path[i]] = cycle_len + (cycle_start_idx - i);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << dist[i];
        if(i != n-1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}