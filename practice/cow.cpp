#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("cow.in","r",stdin);freopen("cow.out","w",stdout);
	ll n; cin>>n;ll c=0; ll co = 0; ll cow = 0;string letters;cin>>letters;
	for(ll i=0; i<letters.length(); i++){
		if(letters[i] =='C'){c++;}
		if(letters[i] == 'O'){co+=c;}
		if(letters[i] == 'W'){cow+=co;}}
	cout<<cow<<endl;}