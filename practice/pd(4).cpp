#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pll pair<ll,ll>

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<pll> pts(n);
        for (ll i = 0; i < n; i++) {
            cin >> pts[i].first >> pts[i].second;
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }else{

        

       
        vector<pair<ll, int>> vx, vy;
        for (int i = 0; i < n; ++i) {
            vx.emplace_back(pts[i].first, i);
            vy.emplace_back(pts[i].second, i);
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());

        set<int> candidates;
        for (int i = 0; i < min(2LL, n); ++i) {
            candidates.insert(vx[i].second);
            candidates.insert(vx[n-1-i].second);
            candidates.insert(vy[i].second);
            candidates.insert(vy[n-1-i].second);
        }

        ll ans = LLONG_MAX;
        for (int skip : candidates) {
            ll min_x = LLONG_MAX, max_x = LLONG_MIN, min_y = LLONG_MAX, max_y = LLONG_MIN;
            for (int i = 0; i < n; ++i) if (i != skip) {
                min_x = min(min_x, pts[i].first);
                max_x = max(max_x, pts[i].first);
                min_y = min(min_y, pts[i].second);
                max_y = max(max_y, pts[i].second);
            }
            ans = min(ans, (max_x - min_x + 1) * (max_y - min_y + 1));
        }
        cout << max(n, ans) << '\n';
        }
    }
}