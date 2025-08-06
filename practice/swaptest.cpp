// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> original, vector<int> cows, int rep){
	if(rep>0){
	for(int i=0; i<cows.size(); i++){
		if(cows[i]!=original[i]){
			return false;
		}
	}
	}else{
		return false;
	}
	return true;
}
int main() {
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	int n, k; cin>>n>>k;
	pair<int,int> a;
	cin>>a.first>>a.second;
	a.first--; a.second--;
	pair<int,int> b;
	cin>>b.first>>b.second;
	b.first--;b.second--;
	int rep=0;
	vector<int> cows(n);
	vector<int> original(n);
	for(int i=1; i<n+1; i++){
		cows[i-1] = i;
		original[i-1] = i;
		}
		
		
	for(int j=0; j<k; j++){
		for(int i=0; i<(a.second-a.first)/2+1; i++){
			int temp = cows[a.first + i];
   			 cows[a.first + i] = cows[a.second - i];
  			  cows[a.second - i] = temp;
			
		
		} 
		
		for(int i=0; i<(b.second-b.first)/2+1; i++){
			int temp = cows[b.first + i];
   			 cows[b.first + i] = cows[b.second - i];
  			  cows[b.second - i] = temp;
				
		
		}
		
		
		}
	
	for(int i=0; i<n; i++){
		cout<<cows[i]<<endl;
	}
}
