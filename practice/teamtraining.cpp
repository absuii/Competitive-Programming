#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &ai : a) cin >> ai;
        
        sort(a.rbegin(), a.rend());

        int teams = 0;
        int team_size = 0;
        for (int i = 0; i < n; ++i) {
            team_size++;
            if (a[i] * team_size >= x) {
                teams++;
                team_size = 0;
            }
        }
        cout << teams << '\n';
    }

    return 0;
}
