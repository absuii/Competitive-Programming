#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n; cin>>n;
	vector<char> cows(n);
	for(ll i=0; i<n; i++){
		cin>>cows[i];
	}
	ll ans=0;
	for(ll i=2; i<n; i++){
		
		ll back=0;
		ll g=0; 
		ll h=0;
		for(ll j=0; j<i+1; j++){
			if(cows[j]=='G'){
				g++;
			}else if(cows[j] =='H'){
				h++;
			}
		}
		if(g==1|| h==1){
				ans++;
				
			}
		for(ll j=i+1; j<n; j++){
			
			if(cows[back] == 'G'){
				g--;
			}else if(cows[back] == 'H'){
				h--;
			}
			back++;
			if(cows[j] == 'G'){
				g++;
			}else if (cows[j] == 'H'){
				h++;
			}
			if(g==1|| h==1){
				ans++;
				
			}
		}
	}
	cout<<ans;
}
