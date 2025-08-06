#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
    string a; cin>>a;
    int ant = 0; int dam = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 'A'){
            ant++;
        }else{
            dam++;
        }
    }
    if(ant == dam){
        cout<<"Friendship";
    }else if(ant < dam){
        cout<<"Danik";
    }else{
        cout<<"Anton";
    }

}
