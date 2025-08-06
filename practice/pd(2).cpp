#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pll pair<ll,ll>

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<pll> pts(n);
        for (ll i=0; i<n; i++){
            cin >> pts[i].first >> pts[i].second;
        }    
        if (n == 1) {
             cout << 1 << '\n';
        }else{
            ll ans = LLONG_MAX;
            for (ll skip = 0; skip < n; ++skip) {
                ll min_x = LLONG_MAX, max_x = LLONG_MIN, min_y = LLONG_MAX, max_y = LLONG_MIN;
                for (ll j = 0; j < n; ++j) if (j != skip) {
                    min_x = min(min_x, pts[j].first);
                    max_x = max(max_x, pts[j].first);
                    min_y = min(min_y, pts[j].second);
                    max_y = max(max_y, pts[j].second);
                }
                ans = min(ans, (max_x - min_x + 1) * (max_y - min_y + 1));
            }
            cout << max(n, ans) << '\n';
        }
    }
}
