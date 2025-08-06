#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool equals(vector<ll>& one, vector<ll>& two){
	for(int i=0; i<(int)one.size(); i++){
		if(one[i] != two[i]){
			return false;
		}
	}
	return true;
}
int main() {
	ll n, k, t;cin>>n>>k>>t;
	vector<ll> cows(n);
	for(ll i =0; i<n; i++){	cows[i] = i;}
	vector<ll> shift(k);
	vector<vector<ll>> prev;
	for(int i=0; i<k; i++){cin>>shift[i];}
	prev.push_back(cows);
	ll count = 0;
	while(equals(prev[0], cows) == false || count==0){
		count++;
		for(ll i=k-1; i>0; i--){
			swap(cows[(shift[i] + count) % n], cows[(shift[i-1] + count) % n]);	
		}
	}
	for(ll j=0; j<t%count-1; j++){
		for(ll i=k-1; i>0; i--){
			swap(cows[(shift[i] + count) % n], cows[(shift[i-1] + count) % n]);	
		}
	}
	for(int i=0; i<cows.size(); i++){
		cout<<cows[i]<<" ";
	}
}
