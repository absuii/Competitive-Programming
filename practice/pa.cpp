#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
    for(int m=0; m<t; m++){
        int n; cin>>n;
        int a = -1, b = -1;
        for(int i=0; i<=99; i++){
            for(int j=0; j<=99; j++){
                if((i+j)*(i+j) == n){
                    a = i;
                    b = j;
                    break;
                }
            }
        }
        if(a==-1){
            cout<<-1<<endl;
        }else{
            cout<<a<<" "<<b<<endl;
        }
    }
}
