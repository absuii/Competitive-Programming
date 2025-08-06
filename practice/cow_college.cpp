
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> cows(n);
	for(int m=0; m<n; m++){cin>>cows[m];}
	sort(cows.begin(), cows.end());
	pair<unsigned long long, int> answer(0,0);
	for(int i = 0; i<n; i++){
		unsigned long long ammount = cows[i];
		unsigned long long sum = ammount * (unsigned long long)abs(n-i);
		
		
		if(sum>answer.first){
			answer.first = sum;
			answer.second = ammount;
		} else if(sum==answer.first){
			if(ammount<answer.second){
				answer.first = sum;
			answer.second = ammount;
			}
		}
	}
	
	cout<<answer.first<<" "<<answer.second;
}
