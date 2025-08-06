// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("stacking.in", "r", stdin);
	freopen("stacking.out", "w", stdout);
	int n, k; cin>>n>>k;
	vector<int> stack(n,0);
	for(int i=0; i<k; i++){
		int a, b; cin>>a>>b;
		stack[a-1]++;
		stack[b-1]--;
		
	}
	
	int count = 0;
	for(int i=0; i<n; i++){
		if(stack[i] > 0){
			count+=stack[i];
		}else if (stack[i]<0){
			count+=stack[i];
		}
		stack[i] = count;
		
	}



	sort(stack.begin(), stack.end());
	cout<<stack[n/2];
}
