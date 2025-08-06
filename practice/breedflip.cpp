// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	int n; cin>>n;
	vector<char> correct(n);
	vector<char> shifted(n);
	vector<bool> compare(n);
	int answer=0;
	bool checker=true;
	for(int m=0;m<n; m++){cin>>correct[m];}
	for(int b=0; b<n; b++){cin>>shifted[b];
	if(correct[b] == shifted[b]){compare[b]=true;}else{compare[b]=false;}}
	for(int i=0; i<n; i++){
		if(compare[i]==false && checker==true){
			checker=false;
			answer++;
		} else if(compare[i]==true){
			checker=true;
		}
	}
	cout<<answer;
}
