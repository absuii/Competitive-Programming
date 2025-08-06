// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	int n; cin>>n;
	vector<char> farm(n);
	for(int i=0; i<n; i++){
		cin>>farm[i];
	}
	int answer=10000000;
	for(int i=0; i<n+1; i++){
		vector<string> data;
		for(int j=0; j<n-i; j++){
			vector<char> temp;
			for(int x=j; x<j+1+i; x++){
				temp.push_back(farm[x]);
				
			}
		string abc (temp.begin(), temp.end());
		data.push_back(abc);
		}
		int x=data.size();
		sort(data.begin(), data.end());
		data.erase( unique( data.begin(), data.end() ), data.end() );
		if(x==data.size()){
			answer=min(answer,i);
		}
	}
	cout<<answer+1;
}
