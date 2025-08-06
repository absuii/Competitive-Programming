#include <bits/stdc++.h>
using namespace std;
vector<int> cows;
bool check(int mid, int l){
	int counter=0;
	for(int i=0; i<cows.size(); i++){
		
		if(cows[i]>=mid){
			counter++;
		} else if(cows[i]+1 == mid && l>0){
			counter++;
			l--;
		}
	}
	if(counter>=mid){
		return true;
	}
	return false;
}

int main() {
	int n, l; cin>>n>>l;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		cows.push_back(a);
	}

	int ans=-1;
	sort(cows.begin(), cows.end());
	int low=0; 
	int mid;
	int high=cows.back();
	while(high>=low){
		mid= (high+low+1)/2;
		bool check_var = check(mid,l);
		if(check_var == true){
			ans=max(mid,ans);
			low=mid+1;
		} else{
			high=mid-1;
		}
	}
	cout<<ans;
}
