#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    ll n; cin >> n;
    vector<pair<ll,ll>> cows(n);
    for (ll i = 0; i < n; i++)
        cin >> cows[i].first >> cows[i].second;
    unordered_map<ll, vector<ll>> rows, cols;
    for (auto [x, y] : cows) {
        rows[y].push_back(x);
        cols[x].push_back(y);
    }
    unordered_map<ll, unordered_map<ll, ll>> horiz, vert;
    auto compute = [&](unordered_map<ll, vector<ll>> &mp, bool isRow) {
        for (auto &[key, vec] : mp) {
            sort(vec.begin(), vec.end());
            int m = vec.size();
            vector<ll> pref(m);
            pref[0] = vec[0];
            for (int i = 1; i < m; i++)
                pref[i] = pref[i-1] + vec[i];
            for (int i = 0; i < m; i++) {
                ll left = 1LL * i * vec[i] - (i ? pref[i-1] : 0);
                ll right = (pref[m-1] - pref[i]) - 1LL * (m-1-i) * vec[i];
                ll dist = (left + right) % MOD;
                if (dist < 0) dist += MOD;

                if (isRow) horiz[key][vec[i]] = dist;
                else vert[key][vec[i]] = dist;
            }
        }
    };
    compute(rows, true);
    compute(cols, false);
    ll ans = 0;
    for (auto [x, y] : cows) {
        ans = (ans + horiz[y][x] * vert[x][y]) % MOD;
    }
    cout << ans;
}
