#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m; cin>>n>>m;
	vector<int> cows(n);
	vector<int> top(m);
	vector<int> bottom(m,1);
	for(int i=0; i<n; i++){cin>>cows[i];}
	for(int i=0; i<m; i++){cin>>top[i];}
	for(int i=0; i<n; i++){
		for(int j =0; j<m; j++){
			if(cows[i] > bottom[j]){
				int t = bottom[j];
				bottom[j] = cows[i] + 1;
				cows[i]+= min(abs(cows[i]-t + 1), top[j]);
			}
			if(bottom[j] == top[j]){
				break;
			}
		}
	}
	for(int i=0; i<n; i++){
		cout<<cows[i]<<endl;
	}
}
