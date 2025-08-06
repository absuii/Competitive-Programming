#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	int n; cin>>n;
	vector<int> order(n);
	vector<int> cow(n);
	set<int> bessie;
	for(int i=0; i<n; i++){
		cin>>order[i];
		cow[i] = order[i];
	}
	sort(cow.begin(),cow.end());
	for(int i=1; i<2*n; i++){
		if(*lower_bound(begin(cow), end(cow), i) != i){
			bessie.insert(i);
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		auto a = bessie.upper_bound(cow[i]);
		if(a != bessie.end()){
			ans++;
			bessie.erase(*a);
		}else{
			bessie.erase(bessie.begin());
		}
	}
	cout<<ans;
}
