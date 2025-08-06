#include <bits/stdc++.h>
using namespace std;
int main() {
  std::vector<int> xpos;
  std::vector<int> ypos;
  int ans=0;
   freopen("triangles.in", "r", stdin);
   freopen("triangles.out", "w", stdout);
  int n; cin>>n;
  for(int p=0;p<n;p++){
    int a,b;
    cin>>a>>b;
    xpos.push_back(a);
    ypos.push_back(b);
  }

  for(int center = 0; center<n; center++){

    for(int pos1 = 0; pos1<n; pos1++){
      
      for(int pos2 = 0; pos2<n; pos2++){
            int area = 0;
            if(xpos[center]==xpos[pos1] && ypos[center]==ypos[pos2]){
              area = (abs(ypos[center]-ypos[pos1]) * (abs(xpos[center]-xpos[pos2])));
            }
            if(xpos[center] == xpos[pos2] && ypos[center] == ypos[pos1]){
              area = (abs(ypos[center] - ypos[pos2]) * (abs(xpos[center] - xpos[pos1])));
            }
            ans = max(ans, area);

      }    
    }
  }
cout<<ans;
}
  
