#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
	int n,m,c, ans = 0; cin>>n>>m>>c;
	vector<int> cows(n);
    for(int i=0; i<n; i++){cin>>cows[i];}
    sort(cows.begin(), cows.end());
    for(int i=0; i<m; i++){ans = max(ans, cows[min((i * c) + c -1, n-1)] - cows[i * c]);}
    cout<<ans;
}
