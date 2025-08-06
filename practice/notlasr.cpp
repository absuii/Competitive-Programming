// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);
	vector<pair<int, string>> cows = {{0, "Annabelle"}, {0, "Bessie"}, {0, "Daisy"}, {0, "Elsie"}, {0, "Gertie"}, {0, "Henrietta"}, {0, "Maggie"}};
	int n; cin>>n;
	for(int i=0; i<n; i++){
		int a; string b;
		cin>>b>>a;
		for(int j=0; j<7; j++){
			if(cows[j].second==b){
				cows[j].first=max(cows[j].first, a);
				
			}
		}
	} 
sort(cows.begin(), cows.end());
int smin=cows[1].first;

string ans=cows[1].second;
for(int i=0; i<cows.size(); i++){
	if(cows[i].first==smin && i!=1){
		ans="Tie";
	}
}
cout<<ans<<"\n";
}
