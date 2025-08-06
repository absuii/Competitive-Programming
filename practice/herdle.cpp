// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int green=0;
	int yellow=0;
	vector<vector<char>> correct(3, vector<char> (3));
	vector<vector<char>> guess(3,vector<char> (3));
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>correct[i][j];
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>guess[i][j];
		}
	}
	vector<vector<int>> ans(3, vector<int>(3));

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(correct[i][j] == guess[i][j]){
				correct[i][j] = '.';
				guess[i][j] = '.';
				green++;
			}
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int a=0; a<3; a++){
				for(int b=0; b<3; b++){
					if(correct[i][j] == guess[a][b] && guess[i][j] !='.' && correct[i][j]!='.'){
						yellow++;
						correct[i][j] = '.';
						guess[i][j] = '.';
					}
				}
			}
		}
	}
cout<<green<<endl<<yellow;

}