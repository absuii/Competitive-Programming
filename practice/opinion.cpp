#include <bits/stdc++.h>
using namespace std;
int searcher(int i, vector<int> list){
	if(list[i]==list[i+1]){
		return list[i];
	}else if(list[i]==list[i+2]){
		return list[i];
	}else if(list[i+1] == list[i+2]){
		return list[i+1];
	}
	return -1;
}
int main() {
	int t; cin>>t;
	for(int m=0; m<t; m++){
		int n; cin>>n;
		vector<int> list(n);
		vector<int> answers;
		for(int b=0; b<n; b++){cin>>list[b];}
		if(n==2){
			if(list[0]==list[1]){
				answers.push_back(list[0]);
			}
		} else if(n==3){
			if(searcher(0, list)!=-1){
				answers.push_back(searcher(0,list));
			}
		} else{
			for(int i=0; i<n-3; i++){
				if(searcher(i,list)!=-1){
					answers.push_back(searcher(i,list));
				}
			}
		}
		sort(answers.begin(), answers.end());
		answers.erase( unique( answers.begin(), answers.end() ), answers.end() );
		if(answers.size()==0){
			cout<<-1;
		}else{
			for(int x=0; x<answers.size(); x++){
				cout<<answers[x];
				if(x!=answers.size()-1){
					cout<<" ";
				}
			}
		}
		cout<<endl;
	}
}
