#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string a; cin>>a;
        map<char,int> characters;
        for(int i=0; i<n; i++){
            characters[a[i]]++;
        }
        bool ans = false;
        for(int i=1; i<n-1; i++){
            if(!ans){
                if(characters[a[i]] > 1){
                    ans = true;
                }
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
