// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int check(vector<int> cows){
	for(int i=cows.size()-1; i> 0; i--){
		if(cows[i]!=cows[i-1] +1){
			return i;
		}
	}
}
int main() {
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	int n; cin>>n;
	vector<int> cows(n);
	for(int i=0; i<n; i++){
		cin>>cows[i];
	}
	cout<<check(cows);
}
