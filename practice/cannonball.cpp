// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,s; cin>>n>>s;
	
	vector<int> line(n);
	vector<int> check(n);
	vector<int> power(n);
	s--;
	int k=1;
	int target=0;
	for(int i = 0; i<n; i++){
		cin>>line[i]>>power[i];
	}
	
int abc=0;
	while(s>-1 && s<n+1){
		 abc++;
		
		if(line[s] == 1){
		if(check[s]==0  && abs(k)>=power[s]){
		target++;
		check[s] = 1;
		
		}
		
		
	} else if(line[s]==0){
		if(k>0){k+=power[s];} else if(k<0){k-=power[s];}
		
		k = k * -1;
		
	}
	s+=k;
	if(abc>10*10*10*10*10*10*10*10){
		s=-1000;
	}
	}

	cout<<target;
}
