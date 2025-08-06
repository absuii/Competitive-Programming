#include <bits/stdc++.h>
using namespace std;
int main() {
   freopen("pails.in", "r", stdin);
   freopen("pails.out", "w", stdout);
  int x, y, m, answer; cin>>x>>y>>m;
  for(int i = 0; i < std::round(m/x)+1; i++){
    for(int j = 0; j < std::round(m/y)+1; j++){
      if((i*x)+(y*j) > m){break;
      } else{
         answer=max(answer, ((i*x)+(y*j))); }   } }
  cout<<answer; }