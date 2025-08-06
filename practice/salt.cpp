#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n,m; cin>>n>>m;
    vector<ll> salt(n);
    for(int i=0; i<n; i++){
        cin>>salt[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        if (salt[i+1] < salt[i] - m) {
            salt[i+1] = salt[i] - m;
        }
    }


    for (ll i = n - 2; i >= 0; --i) {
        if (salt[i] < salt[i+1] - m) {
            salt[i] = salt[i+1] - m;
        }
    }


    for(ll i=0; i<n; i++){
        cout<<salt[i];
        if(i!=n-1){
            cout<<" ";
        }
    }

}
