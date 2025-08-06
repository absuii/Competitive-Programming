#include <bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;

ll simulate(ll k, vector<ll>& cows, ll t){
    ll time = 0;
    priority_queue<ll, vector<ll>, greater<ll>> slots;
    for(int i=0; i<min(k,(ll)cows.size()); i++){
        slots.push(cows[i]);
    }

    for(int i=k; i<cows.size(); i++){
        time=slots.top();
        slots.pop();
        slots.push(time + cows[i]);
    }

    ll end = 0;
    while (!slots.empty()) {
        end = max(end, slots.top());
        slots.pop();
    }

    return end;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
	ll n,t; cin>>n>>t;
    vector<ll> cows(n);
    for(int i=0; i<n; i++){cin>>cows[i];}
    ll low = 0; ll high = n; ll mid = low + (high+low)/2;
    ll ans = n; ll count =0;
    while(count < 100){
        count++;
        mid = low + (high-low)/2;
        ll time = simulate(mid, cows, t);
        if(time > t){
            low = mid+1;

        }else{ 
            ans = min(ans, mid);
            high = mid-1;
        }
    }
    cout<<ans<<"\n";
}
