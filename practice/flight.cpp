#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> all;
vector<bool> visited;
int c = 1;
void reset(){
    for(int i=0; i<visited.size(); i++){
        visited[i] = false;
    }
    c = 1;
}
void dfs(int u){
    if(visited[u]) return;
    visited[u] = true;
    c++;
    for(int s: adj[u]){
        dfs(s);
        if(c || all[s] || all[u]){
            return;
        }
        if(c == adj.size()){
            all[u] = true;
        }
    } 
}

int main() {
	int n, m; cin>>n>>m;
    adj.resize(n);
    all.resize(n);
    visited.resize(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
    }
    int i=0;
    int counter = 0;
    pair<int,int> fail;
    while(i < n){
        reset();
        dfs(i);
        if(all[i]){
            counter++;
        }else{
            for(int a=0; a<n; a++){
                if(!visited[a] && a!=i){
                    fail = {a,i};
                }
            }
            i = 10e9;
        }
    }
    if(counter ==n){
        cout<<"YES";
    }else{
        cout<<"NO"<<endl;
        cout<<fail.first + 1<<" "<<fail.second + 1;
    }
}
