// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	int n; cin>>n;
	vector<vector<int>>adj(n);
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		adj[a-1].push_back(b);
	}
	int ans=101;	
	bool abc=false;
	for(int i=0; i<n; i++){
		if(adj[i].size()==2){
			abc=true;
		}else if(adj[i].size()==0){
			ans=min(i,ans);
		}
	}
	
	if(abc==true){
		cout<<-1;
	}else{
		cout<<ans+1;
	}
}
