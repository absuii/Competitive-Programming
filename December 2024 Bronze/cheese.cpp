#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, q; cin>>n>>q;
	vector<vector<int>> hor(n, vector<int>(n,0));
	vector<vector<int>> ver(n, vector<int>(n,0));
	vector<vector<int>> wid(n, vector<int>(n,0));
	bool search = false;
	int prev = 0;
	for(int l=0;l <q; l++){
		int x,y,z; cin>>x>>y>>z;
		hor[y][x]++;
		ver[z][y]++;
		wid[z][x]++;
		int ans = 0;
		if(hor[y][x] == n){
					prev++;
		}
		if(ver[z][y] == n){
			prev++;
		}
		if(wid[z][x] == n){
			prev++;
		}

		cout<<prev<<endl;
		
			}
		}
		
