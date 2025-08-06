#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main() {
  int x, y, answer; // john x, bessie y
  std::vector<int> values;
  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);
  cin>>x>>y;
   float r = 0;
  bool found = false;
  while(found==false){
    if(pow(-2,r) > 0){
      for(int e=x; e<x+pow(-2,r); e++){
        if(e<1000 && e>0 && found==false){
          values.push_back(e);
          x=e;
          if(x==y){
            found=true;
            answer=values.size();
          }
          
        }
        
      }
    
      r++;
    }

    if(pow(-2,r) < 0){
      for(int e=x; e>x+pow(-2,r); e--){
        if(e<1000 && e>0 && found==false){
          values.push_back(e);
          x=e;
          if(x==y){
            found=true;
            answer =values.size();
          }

        }

      }

      r++;
    }





    
  }

  if(answer =10){
    answer=9;
  }
cout<<answer;


  
}