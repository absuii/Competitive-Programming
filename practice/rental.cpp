#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    ll n, m, r; cin >> n >> m >> r;
    vector<ll> cows(n);
    for (ll &x : cows) cin >> x;
    
    vector<pair<ll,ll>> stores(m); 
    for (int i = 0; i < m; i++) cin >> stores[i].second >> stores[i].first;
    
    vector<ll> rent(r);
    for (ll &x : rent) cin >> x;

    sort(cows.begin(), cows.end(), greater<>());       
    sort(stores.begin(), stores.end(), greater<>());   
    sort(rent.begin(), rent.end(), greater<>());       

    vector<ll> milkProfit(n + 1, 0); 
    int storePtr = 0;
    for (int i = 1; i <= n; i++) {
        ll milk = cows[i - 1];
        ll earned = 0;
        while (storePtr < m && milk > 0) {
            ll use = min(milk, stores[storePtr].second);
            earned += use * stores[storePtr].first;
            milk -= use;
            stores[storePtr].second -= use;
            if (stores[storePtr].second == 0) storePtr++;
        }
        milkProfit[i] = milkProfit[i - 1] + earned;
    }

    vector<ll> rentProfit(n + 1, 0); 
    for (int i = 1; i <= min(n, r); i++) {
        rentProfit[i] = rentProfit[i - 1] + rent[i - 1];
    }


    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll milk = milkProfit[i];
        ll rentAmt = rentProfit[min(n - i, r)];
        ans = max(ans, milk + rentAmt);
    }

    cout << ans << endl;
}
