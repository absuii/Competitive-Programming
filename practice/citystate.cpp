#include <bits/stdc++.h>
using namespace std;
using pss = pair<string,string>;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n;
    cin >> n;

    vector<pss> places(n);
    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;
        places[i] = {city.substr(0,2), state};
    }

    map<pss,int> front, back;
    for(auto &p : places){
        front[p]++;
        back[{p.second, p.first}]++;
    }

    long long ans = 0;
    for(auto &p : places){
        if(p.first != p.second){
            ans += back[p];
        }
    }

    cout << ans / 2 << "\n";
}
