#include <bits/stdc++.h>
using namespace std;

int c = 0;
void flood(vector<vector<bool>>& farm, 
           map<pair<int,int>, set<pair<int,int>>>& roads,
           vector<vector<bool>>& visited, int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    if (farm[i][j]) c++;

    int n = farm.size();
    if (i > 0 && !roads[{i,j}].count({i-1,j}))
        flood(farm, roads, visited, i-1, j);
    if (i < n-1 && !roads[{i,j}].count({i+1,j}))
        flood(farm, roads, visited, i+1, j);
    if (j > 0 && !roads[{i,j}].count({i,j-1}))
        flood(farm, roads, visited, i, j-1);
    if (j < n-1 && !roads[{i,j}].count({i,j+1}))
        flood(farm, roads, visited, i, j+1);
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int n, k, r;
    cin >> n >> k >> r;
    vector<vector<bool>> farm(n, vector<bool>(n));
    map<pair<int,int>, set<pair<int,int>>> roads;

    for (int i = 0; i < r; i++) {
        int a, b, c1, d;
        cin >> a >> b >> c1 >> d;
        a--; b--; c1--; d--;
        roads[{a,b}].insert({c1,d});
        roads[{c1,d}].insert({a,b});
    }

    vector<pair<int,int>> cows(k);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cows[i] = {a,b};
        farm[a][b] = true;
    }

    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(n));
    for (int i = 0; i < k; i++) {
        if (!visited[cows[i].first][cows[i].second]) {
            c = 0;
            flood(farm, roads, visited, cows[i].first, cows[i].second);
            ans += c * (k - c);
        }
    }

    cout << ans / 2 << "\n";
}
