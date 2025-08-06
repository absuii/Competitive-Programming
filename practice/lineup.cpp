// Source: https://usaco.org/index.php?page=viewproblem2&cpid=965

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int n;cin>>n;
	vector<int> test;
	
	vector<vector<int>> requirements(8);
	//0Beatrice,1Belinda,2Bella,3Bessie,4Betsy,5Blue,6Buttercup,and 7Sue.
		vector<string> cows = {"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
		vector<int> permutation = {0,1,2,3,4,5,6,7};
	for(int c=0;c<n;c++){
		string x,y,useless;
		cin>>x;
		
		for(int w=0;w<4;w++){
			cin>>useless;
		}
		cin>>y;
		
		for(int a=0; a<8; a++){
			if(cows[a] == x){
				for(int b=0; b<8; b++){
					if(cows[b] == y){
						requirements[a].push_back(b);
					}
				}
			}
		}


	}
	vector<vector<int>> answers;
	do{
		vector<int> checker;
		for(int x = 0 ; x<8; x++){
			
				for(int i = 0; i< requirements[permutation[x]].size(); i++){
					if(requirements[permutation[x]][i] != permutation[x+1] && requirements[permutation[x]][i] != permutation[x-1] && x!=0 && x!=7){
						checker.push_back(0);
					}
				
			 else if(x==0){
				if(requirements[permutation[x]][i] != permutation[1]){
						checker.push_back(0);
					}
			} else if(x==7){
				if(requirements[permutation[x]][i] != permutation[6]){
						checker.push_back(0);
					}
			}
			}
			
		}
		if(checker.size() == 0){
			answers.push_back(permutation);}
	}while(next_permutation(permutation.begin(), permutation.end()));
	for(int i = 0; i<8;i++){
		cout<<cows[answers[0][i]]<<endl;
	}
}

