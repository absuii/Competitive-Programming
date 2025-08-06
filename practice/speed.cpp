#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);
  std::vector<int> road;
  std::vector<int> bessie;
  std::vector<int> limit;
  std::vector<int> road_seg;
  std::vector<int> cow_seg;
  std::vector<int> speed;
  int ni, mi, na, nb, ma, mb; // all input vars
  cin>>ni>>mi;
  for(int i=0;i<ni;i++){
    cin>>na>>nb;
    limit.push_back(nb);
    road_seg.push_back(na);
  }
  for(int i=0;i<mi;i++){
    cin>>ma>>mb;
    speed.push_back(mb);
    cow_seg.push_back(ma);
  }
//input end, road and bessie vectors to be created with their speed limits
  int z=0;
  for(int x=0; x<ni; x++){
    while(z!=(road_seg[x])){
      road.push_back(limit[x]);
      z++;
    }
  }
  int f=0;
  for(int a=0; a<mi; a++){
    while(f!=(road_seg[a])){
      bessie.push_back(speed[a]);
      f++;
    }
  }
int answer;
int difference;
for(int p=0; p<100; p++){
  if(bessie[p]>road[p]){
    difference = bessie[p]-road[p];
    if(difference>answer){
      answer = difference;
    }
  }
}
cout<<answer;
  return 0;
  
}