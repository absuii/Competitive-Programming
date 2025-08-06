#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main() {
    int t; cin>>t;

    for(int a=0; a<t; a++){
        bool c = false;
        int m, k; cin>>m>>k;
        for(int i=0; i<=m; i++){
            for(int j=0; j<=m; j++){
                for(int l=0; l<=m; l++){
                    if(i+j+l == m && !c){
                        int one, two, three;
                        one = __builtin_popcount((ui)i);
                        two = __builtin_popcount((ui)j);
                        three = __builtin_popcount((ui)l);
                        int ans = one^two;
                        ans = ans^three;
                        if(ans == k){
                            cout<<3<<endl;
                            cout<<i <<" "<<j<<" "<<l<<endl;
                            c = true;
                        }
                    }
                }
            }
        }
        if(!c){
            cout<<-1;
        }
    }
    
}
