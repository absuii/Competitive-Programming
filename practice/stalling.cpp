// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
vector<int> lim;
vector<int> cows;
bool check(){
	for(int i=0; i<cows.size(); i++){
		if(cows[i]>lim[i]){
			return false;
		}
	}
	return true;
}
int main() {
	int n; cin>>n;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		cows.push_back(a);
	}
	for(int i=0; i<n; i++){
		int b; cin>>b;
		lim.push_back(b);
	}
	int ans=0;
	sort(cows.begin(), cows.end());
	do	{
		if(check()==true){
			ans++;
		}
		
	}while(next_permutation(cows.begin(), cows.end()));
	cout<<ans;
}
