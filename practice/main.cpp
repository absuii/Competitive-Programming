#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <algorithm>
int main(){
    int a;
    int b;
    int c;
    int d;
    std::cin>>a>>b;
    std::cin>>c>>d;
  
  //input above

  std::vector<int> john;
  std::vector<int> bessie;

  for(int i = a; i <= b; i++){
    john.push_back(i);
  }
  for(int e = c; e <= d; e++){
    bessie.push_back(e);
  }
  std::vector<int> intersection;
  for(int x = 0; x<=john.size()-1; x++){
    for(int y = 0; y<=bessie.size()-1; y++){
      if(john[x] == bessie[y]){
        intersection.push_back(john[x]);
      }
    }
  }

  int john_var = john.end()-john.begin();
  int bessie_var = bessie.end()-bessie.begin();
  int intersection_var;
  if (intersection.size() == 1){
    intersection_var = 2;
  } else{
    intersection_var = intersection.end()-intersection.begin();
  }
  int total = john_var + bessie_var - intersection_var;
  std::cout<<total;
}