#include <bits/stdc++.h>
using namespace std;
int n = 0;int reached = 0;int minX = 2147483647;int maxX = -2147483647;int minY = 2147483647;int maxY = -2147483647;
vector<bool> visited(n);
vector<vector<int>> adj(n);
vector<pair<int,int>> points(n);
void dfs(int s){
	if(visited[s]) return;
	visited[s] = true;
	minX = min(minX, points[s].first);
	maxX = max(maxX, points[s].first);
	minY = min(minY, points[s].second);
	maxY = max(maxY, points[s].second);
	reached++;
	for(int i: adj[s]){dfs(i);}
}
int main() {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	int m;cin>>n>>m;
	adj.resize(n);
	visited.resize(n);
	points.resize(n);
	for(int i=0; i<n; i++){	cin>>points[i].first>>points[i].second;	}
	for(int i=0; i<m; i++){
		int a,b;cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	int ans = 2147483647;
	for(int i=0; i<n; i++){
		reached = 0;
		maxX = -2147483647; minX = 2147483647; minY = 2147483647; maxY = -2147483647;
		if(!visited[i]){dfs(i);}
		if(reached >=2){ans = min(ans, (abs(maxX - minX) * 2) + (2 * abs(maxY - minY)));}
	}
	cout<<ans;
}