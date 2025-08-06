#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  int ans = 0;
  
  std::vector<int> cowlist(n);
  for(int l=0;l<n;l++){    cin>>cowlist[l]; }

  
  for(int flow1 = 0; flow1 < n; flow1++){
    for(int flow2 = 0; flow2 < n; flow2++){
      //CREATE SUBSET FROM FLOW 1 TO FLOW 2
      std::vector<int> subset;
      bool found = false;
      if(flow1<=flow2){
        
        if (flow1 == flow2){
          subset.push_back(cowlist[flow1]);
        }else{
        for(int border = flow1; border < flow2+1; border++){
          subset.push_back(cowlist[border]);
        }
        } // else
       // subsets have been created!!!!!!!!!!!
      int sum = accumulate(subset.begin(), subset.end(), 0);
      double average = (double)sum/(double)subset.size();

      //average found!!!! search for average in subset now!
      for(int search = 0; search<subset.size(); search++){
        if(subset[search] == average){
          found = true;
        }
      }
        if(found == true){
          ans++;
          
        }



      }


    }     
  }
cout<<ans;
  
}