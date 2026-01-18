#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
	int n, m; cin>>n>>m;
    vector<pair<int,int>> pref(n);
    for(int i=0; i<n; i++){
        cin>>pref[i].first>>pref[i].second;
    }
    for(int i=0; i<n; i++){
        int ans = 0;
        map<int,bool>taken;
        for(int j=i; j<n; j++){
            if(!taken[pref[j].first]){
                ans++;
                taken[pref[j].first] = true;
            }else if(!taken[pref[j].second]){
                ans++;
                taken[pref[j].second] = true;
            }
        }
        cout<<ans<<endl;
    }
}
