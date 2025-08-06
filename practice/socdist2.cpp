#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("socdist2.in", "r", stdin);
	freopen("socdist2.out", "w", stdout);
	int n; int r = 2147483647; int ans = 0; cin>>n; 
	vector<pair<int,int>> cows(n);
	for(int i =0; i<n; i++){cin>>cows[i].first>>cows[i].second;}
	sort(cows.begin(),cows.end());
	for(int i =0; i<n-1; i++){
		if(cows[i].second + cows[i+1].second == 1){r = min(r, abs(cows[i].first - cows[i+1].first));}
	}
	r--;
	vector<bool> a(n,false);
	for(int i = 0; i<n-1; i++){
		if(cows[i].second == 0 && cows[i+1].second == 1){
			if(abs(cows[i].first - cows[i].first) < r){
				a[i+1] = true;
			}
		}
		if(cows[i].second == 1 && cows[i+1].second == 2){
			if(abs(cows[i].first - cows[i].first) < r){
				a[i] = true;
			}
		}
		if(cows[i].second + cows[i+1].second == 2){
			if(abs(cows[i].first - cows[i+1].first) < r){
				a[i] = true;
			}
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
}
