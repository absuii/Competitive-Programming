#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	ll n; cin>>n;
	vector<pair<ll,ll>> cows(n);
	for(ll i=0; i<n; i++){
		cin>>cows[i].first>>cows[i].second;
	}
	ll front = 0; ll back = n-1;
	ll one = 0; ll two = 0;
	sort(cows.begin(), cows.end());
	int count = 0;
	while(front<back){
		ll m = min(cows[front].first,cows[back].first);
		cows[front].first -= m; cows[back].first-=m;
		one+= cows[front].second* m; two+= cows[back].second * m;
		if(cows[front].first == 0){
			front++;
		}
		if(cows[front].second == 0){
			back--;
		}
	}
	cout<<min(one, two);
}