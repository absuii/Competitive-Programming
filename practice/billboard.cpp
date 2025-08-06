// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	vector<vector<int>> graph;
	vector<int> temp;
	for(int i=0; i<2001; i++){
		temp.push_back(0);
	}
	for(int i=0; i<2001; i++){
		graph.push_back(temp);
	}
	for(int i=0; i<2; i++){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int x=b; x<d; x++){
				
		for(int j=a; j<c; j++){
			graph[x+1001][j+1001]=1;
			}
		}
	}
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int x=b; x<d; x++){
				
		for(int j=a; j<c; j++){
			graph[x+1001][j+1001]=0;
			}
		}
		int answer=0;
	for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph[i].size(); j++){
			if (graph[i][j] == 1){
				answer++;
			}
		}
	}
	cout<<answer;
}
