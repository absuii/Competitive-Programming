#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);
  int n; cin>>n;
  
  int ans = 2147483647;
  vector<int> rooms;
  for(int c=0; c<n; c++){
    int a; cin>>a;
    rooms.push_back(a);
  }

for(int i=0; i<n; i++){
vector<int> circle;
  for(int x=i; x<n+i; x++){
    if(x>=n){
      circle.push_back(rooms[x%n]);
    }else{
    circle.push_back(rooms[x]);
    }
  }

  int sum=0;
for(int y=0; y<circle.size(); y++){
  sum+=circle[y] * y;
}
ans = min(ans, sum);  
}
  cout<<ans;
}