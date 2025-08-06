#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lazy.in", "r", stdin);freopen("lazy.out", "w", stdout);
	int n, k, ans=0; cin>>n>>k;
	vector<int> grass(1000001,0);
	for(int i=0; i<n;i++){int a, b; cin>>a>>b;grass[b] = a;}
	for(int i=1; i<grass.size();i++){grass[i] = grass[i] + grass[i-1];}
	for(int i=0; i<grass.size();i++){ans = max(ans,abs(grass[max(0, i-k-1)] - grass[min((int)grass.size()-1, i+k)]));}
	cout<<ans;
}
