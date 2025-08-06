#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> cows){
	for(int i=0; i<cows.size(); i++){
		if(cows[i]!=-1){
			return false;

		}
	}
	return true;
}
int main() {
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	int n; cin>>n;
	vector<int> cows(n);
	for(int i=0; i<n; i++){
		cin>>cows[i];
	}
	if(check(cows)==false){
	int countdown=-2;
	for(int i=n-1; i>=0; i--){
		if(countdown>=0){
			cows[i]=countdown;
			countdown--;
		}else{
			countdown=cows[i];
			countdown--;
		}
	}
	cows[0]=0;
	int mina = 0;
	for(int i=0; i<n; i++){
		if(cows[i]==0){
			mina++;
		}
	}
	if(mina!=1){
		cout<<mina<<" ";
		int maxa = 0;
		for(int i=0; i<n; i++){
			if(cows[i]==-1){
				maxa++;
			}
		}
		cout<<maxa+mina;
	}else{
		cout<<-1;
	}
	}else{
		cout<<1<<" "<<n;
	}
}
