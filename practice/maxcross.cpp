#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int n,k,b; cin>>n>>k>>b;
	vector<bool> light(n, true);
	for(int i=0; i<b; i++){
		int a; cin>>a;
		light[a-1] = false;
	}
	int count=0; int backit=0; int fix=0; int ans=100001;
	
	for(int i=0; i<n; i++){
		count++;
		if(light[i]==false){
			fix++;
		}
		if(count>=k){
			ans=min(ans,fix);
			if(light[backit] == true){
				count--;
			}else if(light[backit] ==false){
				fix--;
				count--;
			}
			backit++;
		}
	}
	cout<<ans;
}
