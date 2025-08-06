#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pll pair<long long, long long>

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<pll> pts(n);
        for (auto& p : pts) cin >> p.first >> p.second;
        if (n == 1) { cout << 1 << '\n'; continue; }

        vector<pair<long long, ll>> vx, vy;
        for (ll i = 0; i < n; ++i) {
            vx.emplace_back(pts[i].first, i);
            vy.emplace_back(pts[i].second, i);
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());

        set<ll> idx;
        for (ll i = 0; i < min((ll)2, n); ++i) {
            idx.insert(vx[i].second);
            idx.insert(vx[n-1-i].second);
            idx.insert(vy[i].second);
            idx.insert(vy[n-1-i].second);
        }

        long long ans = LLONG_MAX;
        for (ll i : idx) {
            long long min_x = LLONG_MAX, max_x = LLONG_MIN, min_y = LLONG_MAX, max_y = LLONG_MIN;
            for (ll j = 0; j < n; ++j) if (j != i) {
                min_x = min(min_x, pts[j].first);
                max_x = max(max_x, pts[j].first);
                min_y = min(min_y, pts[j].second);
                max_y = max(max_y, pts[j].second);
            }
            ans = min(ans, (max_x - min_x + 1) * (max_y - min_y + 1));
        }
        cout << max(ans,n) << '\n';
    }
}