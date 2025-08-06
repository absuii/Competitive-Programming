// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n, k; cin>>n>>k;
	ll ans=0;;
	vector<ll> list(n);
	for(int i=0; i<n; i++){
		cin>>list[i];
	}
	if(n!=1 && n!=2){
	ll d=1;
	for(int i=1; i<n; i++){
		d+=abs(list[i]-list[i-1])+1;
		
		if(d<k){
			ans+=d;
			d=1;
			ans+=k;
		} else if(k==d){
			ans+=d;
			d=1;
			ans+=k;
		}
	}
	} else if(n==1){
		ans=k+1;
	} else if(n==2){
		ans=min((2*k)+2, k+abs(list[1] - list[0])+1);
	}
	cout<<ans;
}