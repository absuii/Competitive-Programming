#include <bits/stdc++.h>
using namespace std;
bool s(pair<int,int> one, pair<int,int> two){
	if(one.first!=two.first){return one.first<two.first;}
	return one.second > two.second;
}
int main() {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int n; cin>>n;
	vector<pair<int,int>> m(n);
	for(int i=0; i<n; i++){	cin>>m[i].first>>m[i].second;}
	sort(m.begin(), m.end(), s);
	int maximum = 0;
	int ans = 0;
	for(int i=0; i<n; i++){
		if(max(maximum,m[i].second) == m[i].second){
			maximum = m[i].second;
			ans++;
		}
	}
	cout<<ans;
}
