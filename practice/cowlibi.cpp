#include <bits/stdc++.h>
using namespace std;
#define x second.first
#define y second.second
int dis(std::pair<int, int> a, std::pair<int, int> b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

int main() {
    int g,n; cin>>g>>n;
    vector<pair<int, pair<int,int>>> grazings(g);
    vector<pair<int, pair<int,int>>> cows(n);
    for(int i=0; i<g; i++){
        cin >>grazings[i].x;
        cin >> grazings[i].y;
        cin >> grazings[i].first;
    }
    sort(grazings.begin(), grazings.end());
    vector<int> time(g);
    for(int i=0;i<g; i++){
        time[i] = grazings[i].first;
    }
    for(int i=0; i<n; i++){
        cin>>cows[i].x;
        cin>>cows[i].y;
        cin>>cows[i].first;
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        auto it = lower_bound(time.begin(), time.end(), cows[i].first);
        if (it != time.begin()) --it; 
        auto it2 = upper_bound(time.begin(), time.end(), cows[i].first);
        int count = 0; int abc = 0;
        if(it!=time.end()){
            count++;
            if(abs(*it - cows[i].first) <= dis(grazings[it - time.begin()].second, cows[i].second)){
                abc++;
            }
        }
        if(it2!=time.end()){
            count++;
            if(abs(*it2 - cows[i].first) <= dis(grazings[it2 - time.begin()].second, cows[i].second)){
                abc++;
            }
        }
        if(count == abc){
            ans++;
        }
    }
    cout<<ans;

}
