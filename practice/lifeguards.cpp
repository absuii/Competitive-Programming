#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);
  int n; cin>>n; //n is the number of lifeguards
  vector<vector<int>> lifeguards;
  for(int i = 0; i<n; i++){
    int a, b;
    vector<int> timeslots;
    cin>>a>>b;
    for(int j = a; j<b; j++){
      timeslots.push_back(j);
    }
    lifeguards.push_back(timeslots);
  }
   int ans = 0;
  for(int excluded = 0; excluded<n; excluded++){ //100
    vector<int> combined;
    for(int i = 0; i<n; i++){ //100
      if(i!=excluded){
        for(int j = 0; j<lifeguards[i].size(); j++){ // 1000
          combined.push_back(lifeguards[i][j]);
        }
      }     
    }
    sort(combined.begin(), combined.end());
    auto it = unique(combined.begin(), combined.end());
    combined.erase(it, combined.end());
    if(combined.size() > ans){
      ans = combined.size();
    }
  }
cout<<ans;
}