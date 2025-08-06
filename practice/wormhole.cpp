#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> weights;
vector<vector<int>> adj;
void dfs(int current, vector<bool>& visited, int maxWeight){
    if(visited[current]) return;
    visited[current] = true;
    for(int s: adj[current]){
        if(weights[{current,s}] < maxWeight){
            dfs(s, visited, maxWeight);
        }
    }
}
int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
	int n, m; cin>>n>>m;
    adj.resize(n);
    
    vector<int> cows(n);
    for(int i=0; i<n; i++){
        cin>>cows[i];
    }
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        int c; cin>>c;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[{a,b}] = c;
        weights[{b,a}] = c;
    }
    vector<int> sorted_cows(cows);
    sort(sorted_cows.begin(), sorted_cows.end());
    int count = 100;
    int low = 0;
    int high = 1e9;
    int mid;
    int start = 0;
    for(int i=0; i<n; i++){
        if(cows[i]!=sorted_cows[i]){
            start = i;
            break;
        }
    }
    bool ans = false;
    while(count--){
        mid = low + (high - low)/2;
        vector<bool> visited(n);
        dfs(start,visited,mid);
        bool works = true;
        for(int i=0; i<n; i++){
            if(cows[i] == sorted_cows[i] || (visited[cows[i]-1] && visited[sorted_cows[cows[i]-1]])){
                
            }else{
                works = false;
            }
        }
        if(works){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout<<((mid == 0) ? -1 : mid);
}
