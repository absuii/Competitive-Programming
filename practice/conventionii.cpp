#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int arrival, duration, id;
    bool operator<(const Cow& o) const {
        return id > o.id; 
    }
};

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n; cin >> n;
    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].arrival >> cows[i].duration;
        cows[i].id = i; 
    }
    sort(cows.begin(), cows.end(), [](const Cow& a, const Cow& b) {
        return a.arrival < b.arrival;
    });
    priority_queue<Cow> waiting;
    int idx = 0; 
    int currentTime = 0;
    int maxWait = 0;
    while (idx < n || !waiting.empty()) {
        while (idx < n && cows[idx].arrival <= currentTime) {
            waiting.push(cows[idx]);
            idx++;
        }
        if (waiting.empty()) {
            currentTime = cows[idx].arrival;
            continue;
        }
        Cow curr = waiting.top(); waiting.pop();
        int waitTime = max(0, currentTime - curr.arrival);
        maxWait = max(maxWait, waitTime);
        if (currentTime < curr.arrival) {
            currentTime = curr.arrival;
        }
        currentTime += curr.duration;
    }
    cout << maxWait << endl;
}