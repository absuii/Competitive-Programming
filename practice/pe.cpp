#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> dangers;
vector<vector<ll>> adj;
vector<ll> ans;
vector<ll> parent;

void reset() {
    for (ll i = 0; i < adj.size(); i++) adj[i] = {};
    for (ll i = 0; i < dangers.size(); i++) {
        dangers[i] = 0;
        ans[i] = 0;
        parent[i] = -1;
    }
}

void set_parents(ll u, ll p) {
    parent[u] = p;
    for (ll v : adj[u]) if (v != p) set_parents(v, u);
}

ll max_alt_sum(ll u, ll sign) {
    ll res = 0, best = LLONG_MIN;
    while (u != -1) {
        res += sign * dangers[u];
        best = max(best, res);
        sign *= -1;
        u = parent[u];
    }
    return best;
}
int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ans.resize(n);
        dangers.resize(n);
        adj.resize(n);
        parent.resize(n);
        reset();
        for (ll i = 0; i < n; i++){
            cin >> dangers[i];
        } 
        for (ll i = 0; i < n - 1; i++) {
            ll a, b; cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }
        set_parents(0, -1);

        for (ll i = 0; i < n; i++){
            ans[i] = max_alt_sum(i, 1);
        }
            

        for (ll i = 0; i < n; i++){
            cout << ans[i] << " ";
        } 
        cout << '\n';
    }
}