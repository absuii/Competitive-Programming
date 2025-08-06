#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
void dfs(int parent, int current, vector<bool>& visited, vector<char>& places, vector<shared_ptr<vector<int>>>& groupings){
    if(visited[current]) return;
    visited[current] = true;
    if (parent == current) {
        groupings[current] = make_shared<vector<int>>();
    }
    if(places[parent] == places[current]){
        groupings[current] = groupings[parent];
    }else{
        groupings[current] = make_shared<vector<int>>();
    }
    groupings[current]->push_back(current);
    for(int s: adj[current]){
        dfs(current,s,visited, places, groupings);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
	int n, m; cin>>n>>m;
    vector<char> places(n);
    adj.resize(n);
    for(int i=0; i<n; i++){
        cin>>places[i];
    }
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<shared_ptr<vector<int>>> groupings(n);
    vector<bool> visited(n);
    dfs(0,0,visited, places,groupings);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;a--;b--;
        char c; cin>>c;
        if(groupings[a] == groupings[b]){
            if(c == places[b]){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<1;
        }
    }
}
