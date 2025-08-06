#include <bits/stdc++.h>
using namespace std;
int searcher(int number, vector<int> cows){
	for(int i=0; i<cows.size(); i++){
		if(cows[i]==number){
			return i;
		}
	}
	return -1;
}
int main() {
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	int n; cin>>n;
	vector<int> cows;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		cows.push_back(a);
	}
	vector<int> sorted(n);
	for(int i=0; i<n; i++){
		sorted[i] = cows[i];
	}
	int ans = 0;
	int pos=-1;
	sort(sorted.begin(), sorted.end());
	for(int i=0; i<n; i++){
		pos = searcher(sorted[0], cows);
		if(pos==0){
			cows.erase(cows.begin());
			sorted.erase(sorted.begin());
		} else{
			swap(cows[0], cows[pos]);
			cows.erase(cows.begin());
			sorted.erase(sorted.begin());
			ans++;
		}
	}
	cout<<ans;
}
