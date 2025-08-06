// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n,t; cin>>n>>t;
	vector<ll> days(t);
	for(int i=0; i<n; i++){
		ll a, b; cin>>a>>b;
		if(a-1 < t){
			days[a-1] = b;
		}
		
	}
	ll sum = 0;
	ll count = 0;
	for(int i=0; i<t; i++){
		sum+=days[i];
		days[i] = sum;
		if(days[i]!=0){
			sum--;
			count++;
		}
	}
	cout<<count;
}