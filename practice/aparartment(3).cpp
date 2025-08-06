#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cows(n);
    vector<int> apart(m);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apart[i];
    }

    sort(cows.begin(), cows.end());
    sort(apart.begin(), apart.end());

    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(cows[i] - apart[j]) <= k) {
            // Assign apartment to cow
            ans++;
            i++;
            j++;
        } else if (apart[j] < cows[i] - k) {
            // Apartment too small, try next apartment
            j++;
        } else {
            // Apartment too big, try next cow
            i++;
        }
    }

    cout << ans << endl;
}
