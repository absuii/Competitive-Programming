// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> dice1, vector<int> dice2){
	int count1 = 0;
	int count2 = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(dice1[i] > dice2[j]){
				count1++;
			} else if(dice1[i] < dice2[j]){
				count2++;
			}
		}
	}
	if(count1>count2){
		return 1;
	}
	if(count2>count1){
		return 2;
	}
	return -1;
}
int main() {
	int n; cin>>n;
	for(int v=0; v<n; v++){
		vector<int> dice1(4);
		vector<int> dice2(4);
		
		for(int i=0; i<4; i++){cin>>dice1[i];}
		for(int i=0; i<4; i++){cin>>dice2[i];}
		int greater = solve(dice1, dice2);
		
		bool check=false;
		if(greater==-1){
			cout<<"no"<<endl;
		}else if(greater==1){ // dice 1 is bigger than dice 2, dice 3 must be bigger than 1 and less than 2
			
			for(int d1=1; d1<11; d1++){
				for(int d2=1; d2<11; d2++){
					for(int d3=1; d3<11; d3++){
						for(int d4=1; d4<11; d4++){
							vector<int> dice3 = {d1,d2,d3,d4};
							int greater1 = solve(dice3, dice1);
							int less = solve(dice2, dice3);
							if(greater1 == 1 && less == 1){
								check=true;
							}
						}
					}
				}
			}
			if(check==true){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		} else if(greater==2){
			for(int d1=1; d1<11; d1++){ //dice 2 is bigger than dice 1, dice 3 must be bigger than 2 and less than 1
				for(int d2=1; d2<11; d2++){
					for(int d3=1; d3<11; d3++){
						for(int d4=1; d4<11; d4++){
							vector<int> dice3 = {d1,d2,d3,d4};
							int greater2 = solve(dice3, dice2);

							int less = solve(dice1, dice3);
							if(greater2 == 1 && less == 1){
								check=true;
							}
						}
					}
				}
			}
			if(check==true){
				cout<<"yes"<<endl;
			} else{
				cout<<"no"<<endl;
			}
		}
	}
}
