#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n; cin>>n;
    vector<ll> cows(n);
    for(ll i=0; i<n; i++)cin>>cows[i];
    sort(cows.begin(),cows.end());
    ll median;
    if(n%2 == 0){
        median = cows[(n/2 + (n-1)/2)/2];
    }else{
        median = cows[n/2];
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans+=(abs(cows[i] - median));
    }
    cout<<ans;
}
