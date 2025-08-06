#include <bits/stdc++.h>
using namespace std;

void flood(vector<vector<bool>>& visited, int i, int j, vector<vector<int>>& weights, int mid){
    if(visited[i][j]) return;
    visited[i][j] = true;
    
    if(i!=0 && abs(weights[i][j] - weights[i-1][j]) <= mid){
        flood(visited, i-1, j, weights, mid);
    }
    if(i!=weights.size()-1 && abs(weights[i][j] - weights[i+1][j])<=mid){
        flood(visited,i+1, j, weights,mid);
    }
    if(j!=0 && abs(weights[i][j] - weights[i][j-1])<=mid){
        flood(visited,i,j-1, weights,mid);
    }
    if(j!=weights[0].size()-1 && abs(weights[i][j] - weights[i][j+1])<=mid){
        flood(visited,i,j+1, weights,mid);
    }
    
}

bool check(vector<vector<bool>>& visited, vector<pair<int,int>>& waypoints){
    for(pair<int,int> i: waypoints){
        if(!visited[i.first][i.second]){
            return false;
        }
    }
    return true;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int n,m; cin>>n>>m;
    vector<pair<int,int>> waypoints;
    vector<vector<int>> weights(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>weights[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a; cin>>a;
            if(a==1){
                waypoints.push_back({i,j});
            }
        }
    }

    int low = 0; int high = 10e9; int mid = low + (high-low)/2;
    int c = 45;
    while(c--){
        mid = low + (high-low)/2;
        vector<vector<bool>> visited(n, vector<bool>(m));
        flood(visited, waypoints[0].first, waypoints[0].second, weights, mid);
        if(check(visited,waypoints)){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    cout<<mid;

}
