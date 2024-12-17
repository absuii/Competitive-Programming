#include <bits/stdc++.h>
using namespace std;

int solve(int n){
	int ans = 0;
	if(n >= 45){ //1
		if(n>=49){
			ans+=5;
		}else{
			ans+=abs(n-45) + 1;
		}
	}
	if(n>= 445){ //2
		if(n>=499){
			ans+=55;
		}else{
			ans+=abs(n-445) + 1;
		}
	}
	if(n>=4445){ //3
		if(n>=4999){
			ans+=555;
		}else{
			ans+=abs(n-4445) +1;
		}
	}
	if(n>=44445){//4
		if(n>=49999){
			ans+=5555;
		}else{
			ans+=abs(n-44445) +1;
		}
	}
	if(n>= 444445){//5
		if(n>=499999){
			ans+=55555;
		}else{
			ans+=abs(n-444445) +1;
		}
	}
	if(n>= 4444445){//6
		if(n>=4999999){
			ans+=555555;
		}else{
			ans+=abs(n-4444445) +1;
		}
	}
	if(n>= 44444445){//7
		if(n>=49999999){
			ans+=5555555;
		}else{
			ans+=abs(n-44444445) +1;
		}
	}
	if(n>= 444444445){//8
		if(n>=499999999){
			ans+=55555555;
		}else{
			ans+=abs(n-444444445) +1;
		}
	}
	if(n>= 4444444445){//9
		if(n>=4999999999){
			ans+=555555555;
		}else{
			ans+=abs(n-4444444445) +1;
		}
	}
	return ans;
}
int main() {
	int n; cin>>n;
	vector<int> cows(n);
	for(int i=0; i<n; i++){
		cin>>cows[i];
	}
	for(int i=0; i<n; i++){
		cout<<solve(cows[i])<<endl;
	}
}
