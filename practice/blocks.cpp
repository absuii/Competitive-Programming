#include <bits/stdc++.h>
using namespace std;

int main() {

  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout); 
  int n; cin>>n;
  vector<int> length;
  vector<vector<char>> boards;
  vector<char> total;
  vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  for(int e=0; e<n; e++){
    string a,b;
    cin>>a>>b;
    vector<char> temp (a.begin(), a.end());
    length.push_back(temp.size());
    temp.insert(temp.end(), b.begin(), b.end());
    length.push_back(temp.size() - length.back());
    boards.push_back(temp);}

for(int o=0; o<boards.size(); o++){
  for(int i=0; i<boards[o].size(); i++){
    total.push_back(boards[o][i]);}
  }

  vector<char> duplicates;
  for(int i =0; i<n; i++){
vector <bool> checker;
   for(int x=0; x<1000; x++){
     checker.push_back(false);

   }


    for(int j=0; j<length[i]; j++){
      
      for(int p=length[i]; p<length[i+1] + length[i]; p++){
        
        if(boards[i][j] == boards[i][p] && checker[p] != true){
          duplicates.push_back(boards[i][j]);
          checker[p] = true;
          checker[j] = true;
        }
      }
    }   
  }

for(int m=0; m<26; m++){
  int ans=0;
  int over = 0;
  for(int i=0; i<total.size(); i++){
    if(total[i] == alphabet[m]){
      ans++;
    }
    
  }

  for(int e=0; e<duplicates.size(); e++){
    
    if(duplicates[e] == alphabet[m]){
      over++;
    }
  }
  cout<<ans-over<<endl;
}







  
}