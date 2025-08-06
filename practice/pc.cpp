#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for(int m =0; m<t; m++){
        int n; cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin>>a[i];
        } 
        int ans = 0,last=-2;
        for (int i = 0; i < n; i++) {
            if (a[i] > last + 1){
                ans++;
                last=a[i];
            }
        }
        cout<<ans<<endl;
    }
}