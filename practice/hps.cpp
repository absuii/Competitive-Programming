#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n; cin>>n;
	vector<int> hoof(n);
	vector<int> paper(n);
	vector<int> sci(n);
	for(int i=0; i<n; i++){
		if(i!=0){
			hoof[i]=hoof[i-1];
			paper[i]=paper[i-1];
			sci[i]=sci[i-1];
		}
		char a; cin>>a;
		if(a=='H'){
			hoof[i]++;
		}else if(a=='P'){
			paper[i]++;
		}else{
			sci[i]++;
		}
	}
	int answer=0;
	for(int i=0; i<n; i++){
		answer=max(answer, max({hoof[i], paper[i], sci[i]}) + max({hoof[n-1] - hoof[i-1], paper[n-1] - paper[i-1], sci[n-1] - sci[i-1]}));
	}
	cout<<answer;
}
