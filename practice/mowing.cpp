#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);
  int n; cin>>n;
  vector<int> movement;
  vector<int> answers;
  vector<char> direction;
  for(int c=0; c<n; c++){
    char a; 
    int b;
    cin>>a>>b;
    direction.push_back(a);
    movement.push_back(b);}
  vector<int>temp;
  for(int v=0; v<2003; v++){
    temp.push_back(-1);}
  vector<vector<int>> grid;
  for(int t=0; t<2003; t++){
    grid.push_back(temp);}
int x = 1001;
  int time=0;
  int y = 1001;
  for(int i = 0; i<n; i++){
    for(int j=0; j<movement[i]; j++){
      if(direction[i]=='N'){
        y--;
        time++;
        if(grid[y][x]==-1){
          grid[y][x]=time;
        }else{
          answers.push_back(abs(time-grid[y][x]));
          
          grid[y][x] = time;
        }
      }

      if(direction[i]=='E'){
        x++;
        time++;
        if(grid[y][x]==-1){
          grid[y][x]=time;
        }else{
          answers.push_back(abs(time-grid[y][x]));
          
          grid[y][x] = time;
        }
      }

      if(direction[i]=='S'){
        y++;
        time++;
        if(grid[y][x]==-1){
          grid[y][x]=time;
        }else{
          answers.push_back(abs(time-grid[y][x]));
          
          grid[y][x] = time;
        }
      }


      if(direction[i]=='W'){
        x--;
        time++;
        if(grid[y][x]==-1){
          grid[y][x]=time;
        }else{
          answers.push_back(abs(time-grid[y][x]));
          
          grid[y][x] = time;
        }
      }
      
    }
  }



int ans = 0;

if(answers.size() == 0){
  ans = 0-1;
}else{
  ans = *min_element(answers.begin(), answers.end());}
  
  cout<<ans;
}