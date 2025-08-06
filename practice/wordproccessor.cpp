#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	int n, k; cin>>n>>k;
	vector<string> cows(n);
	int used = 0; int length = 0; 
	for(int i=0; i<n; i++){cin>>cows[i];}
	while(used!=n){
	
		if(length + (int)cows[used].length() <= k){
			cout<<cows[used];
			length+=(int)cows[used].length();
			used++;
			if(used!=n && length+cows[used].length() <= k){
				cout<<" ";
			}
		}else{
			cout<<"\n";
			length = 0;}
			}
		}
