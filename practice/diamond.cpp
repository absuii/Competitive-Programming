#include <bits/stdc++.h>
using namespace std;

int main() {
   freopen("diamond.in", "r", stdin);
   freopen("diamond.out", "w", stdout);
  int n, k; cin>>n>>k;
  vector<int> a(n);
  for(int t = 0; t < n; t++){    cin>>a[t];  }
  sort(a.begin(), a.end());
  int ans = 0;
  int count = 0;
  int first;
  bool checker = false;
  for(int t = 0; t < n; t++){
    for(int i=0; i<n; i++){
      if(abs(a[t]-a[i])<=k && checker!= true){
        first = a[i];
        checker=true;     }
      if(abs(a[t]-a[i])<=k && abs(a[i]-first)<=k){
        count++;   }   }
    if(count>ans){
      ans = count; }
    count = 0;
    checker = false;
    first = 0; }
  cout<<ans;
}