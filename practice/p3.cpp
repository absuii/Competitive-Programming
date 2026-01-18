// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ll m;cin>>m;
    for(ll t = 0; t < m; t++) {
        string cows; cin>>cows;
        ll n=stoi(cows);
        ll k; cin>>k;
        string r_str; cin>>r_str;
        ll m=n-k+1;
        vector<ll> r(m+1);
        for(ll i=1; i<=m; i++) {
            r[i]=r_str[i-1]-'0';
        }
        ll mini=n+1;
        ll maxi=-1;
        ll free=(k>1?k-1:0);
        ll num =1LL<<free;
        
        for(ll mask=0; mask<num; mask++) {
            vector<ll> s(n+1, 0);
            ll current = mask;
            for(ll d=1; d<k; d++) {
                s[d] = current & 1;
                current >>= 1;
            }
            
            for(ll j=k; j<=n; j++) {
                s[j] = s[j-k]^r[j -k+1];
            }
            ll ones = 0;
            for(ll j=1; j<=n; j++) {
                ll b = s[j]^s[j-1];
                ones += b;
            }
            mini = min(mini, ones);
            maxi = max(maxi, ones);
        }
        cout<<mini<<" "<<maxi;
        cout<<endl;
    }
    return 0;
}