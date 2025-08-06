#include <bits/stdc++.h>
using namespace std;


int main() {
  freopen("gymnastics.in", "r", stdin);
freopen("gymnastics.out", "w", stdout);
  int k, n;
  cin>>k>>n;
  vector<vector<int>> cows;
  for(int q=0; q<k; q++){
    vector<int> temp(n);
    for(int w=0; w<n; w++){
      cin>>temp[w];}
    cows.push_back(temp);}
int ans=0;
    for(int j=1; j<n+1; j++){

      for(int e=1; e<n+1; e++){
        if(e<j){
          //search for numbers
          
          int e_pos, j_pos;
          int count=0;
          for(int i=0; i<k; i++){
            for(int x=0; x<n; x++){
              if(cows[i][x]==e){
                e_pos=x;
              }
              if(cows[i][x]==j){
                j_pos=x;
              }
            }
            if(e_pos<j_pos){
              count++;
            }
          }
          if(count==0 || count==k){
            ans++;
          }
        }
      }
    }
cout<<ans;
}