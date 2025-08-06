#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout); 
  int n; cin>>n;
  vector<vector<string>> desc;
  int ans = 1;
  for(int c=0; c<n; c++){
    string a;
    int b;
    cin>>a>>b;
    vector<string> temp(b);
    for(int l=0; l<b; l++){
      cin>>temp[l];}
    desc.push_back(temp);}
int yes = 1;
for(int i = 0; i<n; i++){
  for(int j = 0; j<n; j++){
    yes = 1;
    for(int x = 0; x<desc[j].size(); x++){
      for(int y = 0; y<desc[i].size(); y++){
        if(desc[j][x] == desc[i][y] && i!=j){
          yes++;}
      }
    }
  }
  ans = max(ans, yes);
}




cout<<ans;
  
}