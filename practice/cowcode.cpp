#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
	string s; ll n; cin>>s>>n;
    ll m = s.length();
    while(m<n){
        m*=2;
    }
    while(n > s.length()) {
        m /= 2;
        if(n > m) {
            n = n - m;
            if(n == 1) {
                n = m;
            } else {
                n = n - 1;
            }
        }
    }
    cout<<s[n-1]<<endl;
}
