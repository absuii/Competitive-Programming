#include <bits/stdc++.h>
using namespace std;
int x, y, K, m; 
int ans = INT_MAX;
map<pair<int,int>,int> visited;
void dfs(int xCurrent, int yCurrent, int k){
    if(k>K) return;
     auto state = make_pair(xCurrent, yCurrent);
    if (visited.count(state) && visited[state] <= k) {
        return;
    }
    visited[state] = k;
     visited[{xCurrent,yCurrent}] = min(visited[{xCurrent,yCurrent}], k);
    ans = min(abs((xCurrent + yCurrent) - m), ans);
    dfs(x, yCurrent, k+1);
    dfs(xCurrent, y, k+1);
    dfs(0, yCurrent, k+1);
    dfs(xCurrent,0, k+1);
    int amount = min(xCurrent, y - yCurrent);
    dfs(xCurrent - amount, yCurrent + amount, k+1);
    amount = min(yCurrent, x - xCurrent);
    dfs(xCurrent + amount, yCurrent - amount, k+1);
}

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin>>x>>y>>K>>m;
    dfs(0,0,1);
    cout<<ans;
}
