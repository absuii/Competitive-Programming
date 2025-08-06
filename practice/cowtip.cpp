#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	int n; cin>>n;
	vector<vector<char>> farm(n, vector<char>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>farm[i][j];}}
	int ans=0;
	for(int i=n-1; i>-1; i--){
		for(int j=n-1; j>-1; j--){
			if(farm[i][j]=='1'){
				ans++;
				for(int x=0; x<i+1; x++){
					for(int y=0; y<j+1; y++){
						if(farm[x][y]=='0'){
							farm[x][y]='1';
						} else{
							farm[x][y]='0';
						}
					}
				}
				
			}
		}
	}
	cout<<ans;
}
