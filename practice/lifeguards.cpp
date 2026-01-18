#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w",stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    set<int> timepoints;
    for (auto [a, b] : intervals) {
        timepoints.insert(a);
        timepoints.insert(b);
    }

    map<int, int> compress;
    vector<int> decompress;
    int id = 0;
    for (int t : timepoints) {
        compress[t] = id++;
        decompress.push_back(t);
    }

    vector<int> covered(id);          
    vector<vector<int>> owners(id);   

    for (int i = 0; i < n; i++) {
        int a = compress[intervals[i].first];
        int b = compress[intervals[i].second];
        for (int j = a; j < b; j++) {
            covered[j]++;
            owners[j].push_back(i);
        }
    }

    int total = 0;
    vector<int> solo(n);  
    for (int i = 0; i < id - 1; i++) {
        int len = decompress[i + 1] - decompress[i];
        if (covered[i] > 0) total += len;
        if (covered[i] == 1) {
            solo[owners[i][0]] += len;
        }
    }

    int worst = *min_element(solo.begin(), solo.end());
    cout << total - worst << endl;
}
