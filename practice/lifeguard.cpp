#include <bits/stdc++.h>
using namespace std;

bool custom(pair<int,int>& one, pair<int,int>& two){
    if(one.first == two.first){
        return one.second < two.second;
    }
    return one.first < two.first;
}

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w",stdout);
	int n; cin>>n;
    vector<pair<int,int>> cows;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        int b; cin>>b;
        cows.push_back({a, 1});
        cows.push_back({b+1,-1});
    }
    sort(cows.begin(), cows.end(), custom);
    int count = 0;
     int ans = 0;
    for(int i=0; i<cows.size(); i++){
        count+=cows[i].second;
        ans=max(count,ans);
    }
    cout<<ans<<endl;
}
