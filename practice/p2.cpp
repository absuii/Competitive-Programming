#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct UF {
    vector<int> par, rankk, s;
    vector<ll> d, val;
    vector<bool> fixed;
    UF(int n) {
        par.resize(n+1);
        rankk.resize(n+1, 0);
        s.resize(n+1, 1);
        d.resize(n+1, 0);
        val.resize(n+1, 0);
        fixed.resize(n+1, false);
        for(int i=0; i<=n; i++){
            par[i]=i;
        }
    }
    tuple<int, int, ll> find(int u) {
        if (par[u] != u) {
            auto [p, sp, dp]=find(par[u]);
            int su=s[u] * sp;
            ll du=(ll)s[u] * dp+d[u];
            s[u]=su;
            d[u]=du;
            par[u]=p;
            return {p, su, du};
        }
        return {u, 1, 0LL};
    }

    bool add_constraint(int x, int y, ll z) {
        auto [rootx, sx, dx]=find(x);
        auto [rooty, sy, dy]=find(y);
        if (rootx == rooty) {
            ll coeff=(ll)sx+sy;
            ll diff=z-dx-dy;
            if (coeff == 0) {
                if (diff != 0) return false;
            } else {
                if (diff % coeff != 0) return false;
                ll req=diff / coeff;
                if (fixed[rootx]) {
                    if (val[rootx] != req) return false;
                } else {
                    fixed[rootx]=true;
                    val[rootx]=req;
                }
            }
            return true;
        } else {
            if (rankk[rootx] < rankk[rooty]) {
                swap(rootx, rooty);
                swap(sx, sy);
                swap(dx, dy);
            }
            par[rooty]=rootx;
            s[rooty]=-sx * sy;
            d[rooty]=(ll)sy * (z-dx-dy);
            if (rankk[rootx] == rankk[rooty]) rankk[rootx]++;
            if (fixed[rooty]) {
                int ss=s[rooty];
                ll dd=d[rooty];
                ll ary=val[rooty];
                ll req=(ll)ss * (ary-dd);
                if (fixed[rootx]) {
                    if (val[rootx] != req) return false;
                } else {
                    fixed[rootx]=true;
                    val[rootx]=req;
                }
            }
            return true;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;cin>>T;
    for (int t=0; t < T; t++) {
        int N, M;
        cin>>N>>M;
        vector<ll> L(N+1), R(N+1);
        for (int i=1; i <= N; i++) cin>>L[i];
        for (int i=1; i <= N; i++) cin>>R[i];

        UF uf(N);
        bool cons=true;
        for (int m=0; m < M; m++) {
            int x, y;
            ll z;
            cin>>x>>y>>z;
            if (!uf.add_constraint(x, y, z)) {
                cons=false;
            }
        }
        if (!cons) {
            cout <<-1<<endl;
            continue;
        }

        vector<vector<int>> members(N+1);
        for (int i=1; i <= N; i++) {
            auto [root, _, __]=uf.find(i);
            members[root].push_back(i);
        }

        ll total=0;
        for (int rt=1; rt <= N; rt++) {
            if (members[rt].empty()) continue;
            if (uf.fixed[rt]) {
                ll a=uf.val[rt];
                int cnt=0;
                for (int i : members[rt]) {
                    auto [_, s, d]=uf.find(i);
                    ll ai=(ll)s * a+d;
                    if (L[i] <= ai && ai <= R[i]) cnt++;
                }
                total += cnt;
            } else {
                vector<pair<ll, int>> events;
                for (int i : members[rt]) {
                    auto [_, s, d]=uf.find(i);
                    ll left, right;
                    if (s== 1) {
                        left=L[i]-d;
                        right=R[i]-d;
                    } else {
                        left=d-R[i];
                        right=d-L[i];
                    }
                    events.emplace_back(left, 1);
                    events.emplace_back(right+1, -1);
                }
                sort(events.begin(), events.end());
                int cur=0, mx =0;
                size_t j=0;
                while (j < events.size()) {
                    ll pos=events[j].first;
                    while (j<events.size()&&events[j].first==pos) {
                        cur+=events[j].second;
                        j++;
                    }
                    mx=max(mx, cur);
                }
                total += mx;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}