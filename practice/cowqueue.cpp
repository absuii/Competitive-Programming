#include <bits/stdc++.h>
using namespace std;
int main(){
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  int n; cin>>n;
  vector<int> que;
  vector<pair<int,int>> order;
  for(int v=0; v<n; v++){
    int a,b; cin>>a>>b;
    pair<int,int> temp (a,b);
    order.push_back(temp);}
  sort(order.begin(), order.end());
  vector<int> time(2 * 10*10*10*10*10*10);
for(int m=0; m<n; m++){
  time[order[m].first-1] = order[m].second;
}
int counter=0;
  for(int i=0; i<time.size(); i++){
    if(time[i]!=0){
      if(que.size()==0){
      que.push_back(time[i]+1);}else{
        que.push_back(time[i]);
      }
    }
    if(que.size()!=0){
      counter++;
      time[i]=-1;
      if(counter==que[0]){
        que.erase(que.begin());
        counter=0;
      }
    }
    

  }
  int answer=0;

  for(int i=0; i<time.size(); i++){
    if(time[i]!=0){
      answer=distance(time.begin(), time.begin()+i);
    }
  }
  cout<<answer+1;
}