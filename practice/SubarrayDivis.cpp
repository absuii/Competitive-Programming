#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n; cin>>n;
    ll numbers[n];
    for(ll i=0; i<n; i++){
        cin>>numbers[i];
    }
    ll pSum = 0;
    ll ans = 0;
    map<ll, ll> sums;
    sums[0] = 1;
    for(ll i=0; i<n; i++){
        pSum+=numbers[i];
        ans += sums[pSum % n];
        sums[pSum % n]++;
    }
    cout<<ans;
}
