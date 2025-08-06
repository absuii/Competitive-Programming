// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
bool check(int n, int dif[]){
	for(int i=0; i<n; i++){
		if(dif[i] !=0){
			return false;
		}
	}
	return true;
}
int sign(int x){
	if(x>0){
	return -1;
	}
	if(x<0){
		return 1;
	}
	return 0;
}

int main() {
	int n; cin>>n;
	
	vector<int> cows(n);
	vector<int> cor(n);
	int diff[n];
	for(int i=0; i<n; i++){
		cin>>cor[i];
	}
	for(int i=0; i<n; i++){
		cin>>cows[i];
		
		diff[i] = cor[i] - cows[i];
	}
	int ans=0;
	int prev=-1;
	
	while(check(n, diff) == false){
		
		for(int i=0; i<n; i++){
			if(i==0){
					prev = (sign(diff[i]) * -1);
				if(diff[i]!=0){
					ans++;
					
				}
				diff[i]+=sign(diff[i]);
				
				
			}else{
				
				if(prev == (sign(diff[i]) * -1) && prev!=0){
						prev = (sign(diff[i]) * -1);
					diff[i]+=sign(diff[i]);
				}else if(sign(diff[i]) * -1 !=0   && prev!=sign(diff[i]) * -1) {
						prev = (sign(diff[i]) * -1);
					diff[i] += sign(diff[i]);
					ans++;
					
				}else{
					prev=sign(diff[i]);
				}
			}
		
			
			
		}
		
	}
	
	cout<<ans;
}
