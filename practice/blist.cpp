#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);
  int n; cin>>n;
  vector<int> start_time;
  vector<int> end_time;
  vector<int> buckets_needed;
  for(int c=0; c<n; c++){
    int a,b,d;
    cin>>a>>b>>d;
    start_time.push_back(a);
    end_time.push_back(b);
    buckets_needed.push_back(d);}
  vector<int> buckets_left;
buckets_left.push_back(0);
int high = *max_element(end_time.begin(), end_time.end());
  for(int i=1; i<high+1; i++){
    for(int j=0; j<n; j++){
      if(start_time[j] == i) {
        buckets_left.push_back(buckets_left.back() - buckets_needed[j]);
      }
  }
    for(int e=0; e<n; e++){
        if(end_time[e] == i) {
          buckets_left.push_back(buckets_left.back() + buckets_needed[e]);
        }
    }
}
  int ans = *min_element(buckets_left.begin(), buckets_left.end());
  cout<<abs(ans);
  }
