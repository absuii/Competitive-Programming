#include <bits/stdc++.h>
using namespace std;

int search(vector<vector<char>> mirrors, int y, int x, char direction, int ans, vector<vector<bool>> found){
	int n = (int)mirrors.size();
	int m = (int)mirrors[0].size();
	if(x!=-1 && x!=m && y!=-1 && y!=n){
		ans++;
		if(found[y][x]){
			return -1;
		}
		found[y][x] = true;
		if(direction == 'U'){
			if(mirrors[y][x] == '/'){
				return search(mirrors, y, x+1, 'R', ans,found);
			}else{
				return search(mirrors, y, x-1, 'L', ans, found);
			}
		}
		if(direction == 'D'){
			if(mirrors[y][x] == '/'){
				return search(mirrors, y+1, x-1, 'L', ans, found);
			}else{
				return search(mirrors, y+1, x+1, 'R', ans, found);
			}
		}
		if(direction == 'L'){
			if(mirrors[y][x] == '/'){
				return search(mirrors, y+1,x, 'D', ans, found);
			}else{
				return search(mirrors, y-1, x, 'U', ans, found);
			}
		}
		if(direction == 'R'){
			if(mirrors[y][x] == '/'){
				return search(mirrors, y-1,x, 'U', ans, found);
			}else{
				return search(mirrors, y+1,x , 'D', ans, found);
			}
		}

	}
	return ans;

}
int main() {
	freopen("mirror.in", "r", stdin);
	freopen("mirror.out", "w", stdout);
	int n, m; cin>>n>>m;
	vector<vector<char>> mirrors(n, vector<char> (m));
	vector<vector<bool>> found(n, vector<bool> (m, false));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>mirrors[i][j];
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		if(ans!=-1){
			int one = search(mirrors, i, 0, 'R', 0, found);
			int two = search(mirrors, i, n-1, 'L', 0, found);
			ans = max(ans, one);
			ans = max(ans, two);
			if(one == -1 || two==-1){
				ans = -1;
			}
		}
		
	}
	for(int i=0; i<m; i++){
		if(ans!=-1){
			int one = search(mirrors, 0, i, 'D', 0, found);
			int two = search(mirrors, m-1, i, 'U', 0, found);
			ans = max(ans, one);
			ans = max(ans, two);
			if(one == -1 || two == -1){
				ans=-1;
			}
		}
	}
	cout<<ans;
}
