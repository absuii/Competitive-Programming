#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("haybales.in", "r", stdin); freopen("haybales.out", "w", stdout);
	int n, q; cin>>n>>q;
	vector<int> bale(n);
	for(int i=0; i<n; i++){cin>>bale[i];}
	sort(bale.begin(), bale.end());
	for(int i=0; i<q; i++){		int a, b; cin>>a>>b;
		cout<<abs((lower_bound(bale.begin(), bale.end(), a) - bale.begin()) - (upper_bound(bale.begin(), bale.end(), b) - bale.begin()))<<endl;	}}