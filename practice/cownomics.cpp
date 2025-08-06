#include <bits/stdc++.h>
using namespace std;
int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
int n;
int m;
cin>>n>>m;
  vector<vector<char>> spots(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { cin >> spots[i][j]; }
  }

  vector<vector<char>> plain(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { cin >> plain[i][j]; }
  }

int ans=0;
  for(int i=0; i<m; i++){
    int count = 0;
    for(int j=0; j<n; j++){
      for(int y=0; y<n; y++){
        if(spots[j][i] == plain[y][i]){
          count++;
        }
      }
    }
    if(count==0){
      ans++;
    }
  }


  cout<<ans;
}