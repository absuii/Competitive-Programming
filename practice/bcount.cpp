// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int n,q; cin>>n>>q;
	vector<int> hp(n); // id - 1
	vector<int> gp(n); // id - 2
	vector<int> jp(n); // id - 3

	for(int i=0; i<n; i++){
		if(i!=0){
			hp[i]=hp[i-1];
			gp[i]=gp[i-1];
			jp[i]=jp[i-1];
		}
		int x; cin>>x;
		if(x==1){
			hp[i]++;
		}else if(x==2){
			gp[i]++;
		}else if(x==3){
			jp[i]++;
		}
	}
	
	for(int i=0; i<q; i++){
		int a,b; cin>>a>>b;
		if(a!=1 && b!=1 && a!=b) {
			cout<<hp[b-1] - hp[a-2]<<" "<<gp[b-1] - gp[a-2]<<" "<<jp[b-1] - jp[a-2]<<endl;
		} else if(a==b && a!=1){
			cout<<hp[a-1] - hp[a-2]<<" "<<gp[a-1]-gp[a-2]<<" "<<jp[a-1] - jp[a-2]<<endl;
		} else if(a==1 && b!=1){
			cout<<hp[b-1]<<" "<<gp[b-1]<<" "<<jp[b-1]<<endl;
		} else if(a==b && a==1){
			cout<<hp[0]<<" "<<gp[0]<<" "<<jp[0]<<endl;
		}
	}
}
