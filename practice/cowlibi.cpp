#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pll pair<ll,ll>

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<pll> pts(n);
        vector<ll> xs, ys;
        for (ll i = 0; i < n; i++) {
            cin >> pts[i].first >> pts[i].second;
            xs.push_back(pts[i].first);
            ys.push_back(pts[i].second);
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        ll ans = LLONG_MAX;
        // Try all combinations of removing one of the min/max/second min/second max x or y
        for (int xi = 0; xi < 2; ++xi) {
            for (int xj = 0; xj < 2; ++xj) {
                for (int yi = 0; yi < 2; ++yi) {
                    for (int yj = 0; yj < 2; ++yj) {
                        ll min_x = xs[xi];
                        ll max_x = xs[n-1-xj];
                        ll min_y = ys[yi];
                        ll max_y = ys[n-1-yj];
                        if (min_x > max_x || min_y > max_y) continue;
                        ans = min(ans, (max_x - min_x + 1) * (max_y - min_y + 1));
                    }
                }
            }
        }
        cout << max(n, ans) << '\n';
    }
}