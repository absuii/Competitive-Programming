#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> cows;
	for(int i=0; i<n; i++){
		int a;cin>>a;		
		cows.push_back(a%2);
	}
	int ans=0;
	int i=0;
	while(i<n){
		bool abc = false;
		int a = i%2;
		for(int j=0; j<cows.size(); j++){
			if(cows[j]==a && abc==false){
				ans++;
				cows.erase(cows.begin()+j);
				abc=true;
			}
		}bool check = false;
		if(abc==false){
			for(int j=0; j<cows.size(); j++){
				for(int l=0; l<cows.size(); l++){
					if(j!=l &&check!=true && (cows[j]+cows[l])%2 == a){
						
						ans++;
						check=true;
						cows.erase(cows.begin() + min(l,j));
						cows.erase(cows.begin()+max(l,j)-1);
						
					}
				}
			}
		}
		
		i++;if(cows.size()==1 && i%2!=cows[0]){
			ans--;
			i=n+100;
		}
		if(check==false && abc==false){
			i=n+100;
		}
	}
	cout<<ans;
}
