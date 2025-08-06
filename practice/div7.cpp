// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	ll n;cin>>n;

	vector<ll> rp(n);
	for(ll i=0; i<n; i++){
		cin>>rp[i];
		if(i>0){
		rp[i]+=rp[i-1];
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		for(int x=i; x<n; x++){
			if(i<=x){
				if(abs(rp[x]-rp[i]) % 7 == 0){
					ans=max(x-i, ans);
				}
			}
		}
	}
	cout<<ans;
}
