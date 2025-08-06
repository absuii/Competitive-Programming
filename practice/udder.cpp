#include <bits/stdc++.h>
using namespace std;
bool check(vector<char> tar, vector<char> built){
	if(tar.size()!=built.size()){
		return false;
	}
	for(int i=0; i<tar.size(); i++){
		if(tar[i]!=built[i]){
			return false;
		}
	}
	return true;
	}
int main() {
	int a = 26;
	vector<char> alph(a);
	for(int i=0; i<a; i++){
		cin>>alph[i];
	}
	 string abc; cin>>abc;
	 vector<char> tar(abc.length());
	 for(int i=0; i<tar.size(); i++){
		 tar[i] = abc[i];
	 }
	vector<char> comp;
	int ans=0;
	while(check(tar, comp) == false){
		
		ans++;
		for(int i=0; i<a; i++){
			if(alph[i] == tar[comp.size()]){
				comp.push_back(alph[i]);
			}
		}
	}



cout<<ans;
}
