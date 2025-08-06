#include <bits/stdc++.h>
using namespace std;
bool s(int o, int t){
	return o>t;
}
int main() {
	freopen("lemonade.in","r",stdin);
	freopen("lemonade.out", "w", stdout);
	int n;cin>>n;
	vector<int> cows(n);
	int waiting = 0;
	for(int i=0; i<n; i++){
		cin>>cows[i];
	}
	sort(cows.begin(),cows.end(),s);
	for(int i=0; i<n; i++){
		if(waiting <= cows[i]){
			waiting++;
		}
	}
	cout<<waiting;
}
