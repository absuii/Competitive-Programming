
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n, a, b; cin>>n>>a>>b;
    map<ll, ll> cows;
    for(ll i=0; i<n; i++){
        ll c,d; cin>>c>>d;
        cows[d] = c;
    }
    
    ll ans = 0;
    for(auto it = cows.rbegin(); it!=cows.rend(); ++it){
        ll key = it->first;
        ll aT = a - key;
        if(aT!=key){
            ll sA = min(cows[aT], cows[key]);
            ans+=sA;
            cows[aT] -=sA;
            cows[key]-=sA;
        }
    
        ll bT =b-key;
        if(bT!=key){
            ll sB = min(cows[bT], cows[key]);
            ans+=sB;
            cows[bT] -=sB;
            cows[key]-=sB;
        }
        
    }
    //equal
    for(const auto& [key,value] : cows){
        if(key * 2 == a){
            ll remove = (ll)(cows[key]/2);
            ans+=remove;
            cows[key]-=remove;
        }
        if(key * 2 == b){
            ll remove = (ll)(cows[key]/2);
            ans+=remove;
            cows[key]-=remove;
        }
    }
   
    cout<<ans;
}

