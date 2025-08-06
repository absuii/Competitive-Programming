#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	int n,k; cin>>n>>k;
	vector<int> d(n);
	for(int i=0; i<n; i++){	cin>>d[i];}
	sort(d.begin(), d.end());
	int back = 0; int ans=0; int front = 0;
	while(front<n){
		int diff = d[front] - d[back];
		if(diff>k){back++;}else{ans=max(ans, diff); front++;}}
	cout<<ans;}