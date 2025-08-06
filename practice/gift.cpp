#include <bits/stdc++.h>
using namespace std;
void swp(vector<int>& values, int one, int two){
    int temp = values[one];
    values[one] = values[two];
    values[two] = temp;
}
void dfs(vector<int>& values, vector<vector<bool>>& visited, vector<vector<int>>& adj, int current, int prior, vector<vector<int>>& matches){
    if(visited[current][prior]) return;
    visited[current][prior] = true;
    visited[prior][current] =true;
    for(int s: adj[current]){
        if(matches[current][values[current]] > matches[current][values[s]] && matches[s][values[current]] < matches[s][values[s]]){
            swp(values,current,s);
        }
        dfs(values,visited,adj,s,current, matches);
    }
}
int main() {
	int n; cin>>n;
    vector<vector<int>> p(n, vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>p[i][j];
            p[i][j]--;
        }
    }
    vector<int> values(n);
    for(int i=0; i<n; i++){
        values[i]=i;
    }
    vector<vector<bool>> visited(n, vector<bool>(n));
    vector<vector<int>> matches(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matches[i][p[i][j]] = j;
        }
    }
    dfs(values,visited, p, 0, 0, matches);
    for(int i=0; i<n;i++){
        cout<<values[i]+1<<endl;
    }
}
