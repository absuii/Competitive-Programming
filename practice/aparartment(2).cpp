#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cows(n);
    vector<int> apart(m);
    map<int, int> apartLeft;
    set<int> remaining;
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apart[i];
        apartLeft[apart[i]]++;
        remaining.insert(apart[i]);
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cow = cows[i];
        pair<int, int> best = {INT_MAX, -1};

        auto it = remaining.lower_bound(cow);
        if (it != remaining.end() && abs(*it - cow) <= k) {
            best = {abs(*it - cow), *it};
        }
        if (it != remaining.begin()) {
            --it;
            if (abs(*it - cow) <= k && abs(*it - cow) < best.first) {
                best = {abs(*it - cow), *it};
            }
        }

        if (best.second != -1) {
            ans++;
            apartLeft[best.second]--;
            if (apartLeft[best.second] == 0) {
                remaining.erase(best.second);
            }
            // Debug print
            //cerr << "Cow " << cow << " assigned to apartment " << best.second << endl;
        }
    }
    cout << ans << endl;
}
