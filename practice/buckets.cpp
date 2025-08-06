#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	pair<int,int> rock;
	pair<int,int> barn;
	pair<int,int>lake;
	vector<vector<char>> farm(10, vector<char>(10));
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cin>>farm[i][j];
			if(farm[i][j]=='R'){
				rock.first = i;
				rock.second=j;
			}if(farm[i][j]=='B'){
				barn.first = i;
				barn.second=j;
			}if(farm[i][j]=='L'){
				lake.first = i;
				lake.second=j;
			}
		}
	}
	if(barn.second==rock.second && barn.second==lake.second){
		cout<<abs(lake.first-barn.first)+1;
	} else if(barn.first==rock.first && rock.first==lake.first){
		cout<<abs(barn.second-lake.second)+1;
	}else{
	cout<<abs(lake.second-barn.second) + abs(lake.first-barn.first)-1;
	}

}
