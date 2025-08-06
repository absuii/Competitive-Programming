// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
bool same(vector<int> list){
	for(int i=0; i<list.size()-1; i++){
		if(list[i]!=list[i+1]){
			return false;
		}
	}
	return true;
}
int main() {
	int t; cin>>t;
	for(int m=0; m<t; m++){
		
		int answer=100000000;
		int n; cin>>n;
		vector<int> list;
		int sum=0;
		int maxi=-1;
		
		for(int i=0; i<n; i++){
			int a; cin>>a;
			list.push_back(a);
			sum+=a;
			maxi=max(maxi,a);
			
		}
		
		int counter=0;
		bool check=true;
		
		
		
		if(same(list)==false){
while(*min_element(list.begin(), list.end())==0 && !list.empty()){
			counter++;
			check=false;
			list.erase(min_element(list.begin(), list.end()));
		}
		
		vector<int> factors;
		for(int i=1; i<=sum; i++){
			if(sum%i==0 && i>=maxi){
				factors.push_back(i);
				
			}
		}
		
		for(int i=0; i<factors.size(); i++){
			int prev_sum=0;
			int ans = counter;
			int seg=0;
			for(int j=0; j<list.size(); j++){
				if(prev_sum!=0){
					ans++;
				}
				prev_sum+=list[j];
				
				if(prev_sum==factors[i]){
					seg++;
					prev_sum=0;
				} else if (prev_sum>factors[i]){
					break;
				}
			}
			if(seg==sum/factors[i]){
				answer=min(ans, answer);
			}
		}

	cout<<answer<<endl;
		} else if(list.size()==0 && check==false){
			cout<<0<<endl;
		}
		else if(check==false){
			cout<<list.size()-1+counter<<endl;
		}
			else{
			cout<<0<<endl;
		}

	}




}
