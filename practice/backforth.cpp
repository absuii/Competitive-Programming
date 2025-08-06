
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);
  vector<int> barn1(10);
  vector<int> barn2(10);
  vector<int> answers;
for(int a=0; a<10; a++){
  cin>>barn1[a];}
for(int b = 0; b<10; b++){
  cin>>barn2[b];}

for(int b11 = 0; b11<10; b11++){
  for(int b12 = 0; b12<10; b12++){
    for(int b21 = 0; b21<11; b21++){
      for(int b22=0; b22<11; b22++){
        int sum=1000;
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0; i<10; i++){  temp1.push_back(barn1[i]);  }
        for(int i=0; i<10; i++){  temp2.push_back(barn2[i]);  }
        temp2.push_back(temp1[b11]);
         sum-=temp1[b11];
        temp1.erase(temp1.begin() + b11);
       

        temp1.push_back(temp2[b21]);
        sum+=temp2[b21];
        temp2.erase(temp2.begin() + b21);
        
        
        temp2.push_back(temp1[b12]);
        sum-=temp1[b12];
        temp1.erase(temp1.begin() + b12);
        

      temp1.push_back(temp2[b22]);
      sum+=temp2[b22];
        temp2.erase(temp2.begin() + b22);
        
      answers.push_back(sum);
      }
    }
  }
}
sort(answers.begin(), answers.end());
answers.erase(unique(answers.begin(), answers.end()), answers.end());

cout<<answers.size();
}