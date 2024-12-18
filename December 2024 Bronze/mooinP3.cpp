#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, f; cin>>n>>f;
	vector<char> cows(n);
	for(int i=0; i<n; i++){
		cin>>cows[i];
	}

	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	set<string> ans;
	for(int i=0; i<n; i++){
		for(int j=0; j<alphabet.size(); j++){
			int temp = cows[i];
			cows[i] = alphabet[j];
			map<string, int> answers;
			set<string> key;
			for(int a =0; a<n-2; a++){
				string moo = string(1, cows[a]) + string(1, cows[a+1]) + string(1,cows[a+2]);
				if(moo[1] == moo[2] && moo[0] != moo[1]){
					answers[moo]+=1;
					key.insert(moo);
				}
			}
			for(string a:key){
				if(answers[a] >=f){
					ans.insert(a);
				}
			}
			cows[i] = temp;
		}
	}
	cout<<ans.size()<<endl;
	for(string i:ans){
		cout<<i<<endl;
	}
	
}
