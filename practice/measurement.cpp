#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
 int n; cin>>n;
  vector<int> day;
  vector<int> cow;
  vector<int> count = {7,7,7};
  vector<int> change;
for(int z=0; z<n;z++){
  int a;
  string b;
  int c;
  cin>>a>>b>>c;
  day.push_back(a);
  change.push_back(c);
  if(b=="Bessie"){
    cow.push_back(0);
  } else if(b=="Elsie"){
    cow.push_back(1);
  }else if(b=="Mildred"){
    cow.push_back(2);}
  
}
  auto prev_max = max_element(count.begin(), count.end());
  int prev_amount = 3;
  int ans=0;
int high = *max_element(day.begin(), day.end());
for(int i=0; i<high+1; i++){
  for(int j=0; j<n; j++){
    if(day[j] == i){
      count[cow[j]] += change[j];  
      auto max = max_element(count.begin(), count.end());
      int amount=0;
      for(int u=0; u<3; u++){
        if(count[u] == *max){
          amount++;
        }}
        if(amount!=prev_amount){
          ans++;
        }else if(prev_max!=max){
        ans++;
      }
      prev_max = max;
      prev_amount = amount;
        
      
    }    
  }




  
}




  cout<<ans;
}