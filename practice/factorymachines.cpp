#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll production(ll k, ll time){
    return (ll) time/k;
}

int main() {
	ll n,t; cin>>n>>t;
    vector<ll> machines(n);
    for(int i=0; i<n; i++){
        cin>>machines[i];
    }
    ll high = INT_MAX;
    ll low = 0;
    ll mid; ll count = 0; ll ans = LLONG_MAX;
    while(count<100){
        count++;
        mid = (high-low)/2 + low;
        ll made = 0;
        for(int i=0; i<n; i++){
            made+=production(machines[i], mid);
        }
        if(made >= t){
            high = mid;
            ans = min(mid, ans);
        }else if(made < t){
            low = mid;
        }
    }
    cout<<ans;
}
