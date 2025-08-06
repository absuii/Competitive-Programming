#include <bits/stdc++.h>
using namespace std;

double dif(int x1, int y1, int x2, int y2){return sqrt(abs(x1-x2) * abs(x1-x2) + abs(y1 - y2) * abs(y1 - y2));}
int ans = 0;
int n = 0;
vector<bool> visited(200, false);
vector<vector<int>> adj(200);
void dfs(int s){
	if(visited[s]){return;}
	else{ans++;}
	visited[s] = true;
	for(int i:adj[s]){dfs(i);}
}

void reset(){
	for(int i=0; i<n; i++){
		visited[i] = false;
	}
	ans = 0;
}
int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin>>n;
	vector<int> power(n);
	vector<int> x(n);
	vector<int> y(n);
	for(int i=0; i<n; i++){cin>>x[i]>>y[i]>>power[i];}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i!=j){
				if(dif(x[i], y[i], x[j], y[j]) <= power[i]){
					adj[i].push_back(j);
				}
			}
		}
	}

	int answer = 0;
	for(int i=0; i<n; i++){
		reset();
		dfs(i);
		answer = max(ans, answer);
	}

	cout<<answer;

}
