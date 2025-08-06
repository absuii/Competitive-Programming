#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowrow.in", "r", stdin);
	freopen("cowrow.out", "w", stdout);
	int n; cin>>n;
	vector<int> cows(n);
	for(int i=0; i<n; i++){
		cin>>cows[i];
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		vector<int> ne;
		for(int j=0; j<n; j++){
			if(cows[j] != cows[i]){
				ne.push_back(cows[j]);
			}
		}
		int count = 0;
		for(int j=0; j<ne.size()-1; j++){
			if(ne[j] == ne[j+1]){
				count++;				
				ans = max(ans, count);
			}else{
				if(count!=0){
					count++;
				}
				ans = max(ans, count);
				count= 0;
			}
		}
	}
	cout<<ans;
}
