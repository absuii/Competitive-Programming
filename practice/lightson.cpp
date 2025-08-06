#include <bits/stdc++.h>
using namespace std;

void flood(vector<vector<bool>>& lighted, vector<vector<bool>>& visited, vector<vector<vector<pair<int,int>>>>& matches, int i, int j, int n){
    if(visited[i][j]) return;
    if(!lighted[i][j]) return;
    
        for(pair<int,int> p : matches[i][j]){
            lighted[p.first][p.second] = true;
        }
    
    visited[i][j] = true;
    if(i!=0){
        flood(lighted,visited,matches,i-1, j, n);
    }
    if(i!=n-1){
         flood(lighted,visited,matches,i+1, j,n);
    }
    if(j!=0){
         flood(lighted,visited,matches,i, j-1, n);
    }
    if(j!=n-1){
         flood(lighted,visited,matches,i, j+1, n);
    }
    
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
	int n, m; cin>>n>>m;
    vector<vector<bool>> lighted(n, vector<bool>(n));
    vector<vector<vector<pair<int,int>>>> matches(n, vector<vector<pair<int,int>>>(n));
    for(int i = 0; i < m; i++){
        int x, y, a, b; 
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        matches[x][y].push_back({a, b});
    }
    vector<vector<bool>> visited(n, vector<bool>(n));
    lighted[0][0] = true;
    for(int i=0; i<n*n; i++){
        for(int j=0; j<n; j++){
            for(int s=0; s<n; s++){
                visited[j][s] = false;
            }
        }
        flood(lighted, visited, matches, 0, 0, n);
    }
    int c = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(lighted[i][j]){
                c++;
            }
        }
    }
    cout<<c;

}
