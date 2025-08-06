#include <bits/stdc++.h>
using namespace std;
int area = 0;
int perimeter = 0;
int edge(vector<vector<char>> &grid, int y, int x){
	int ans = 0;
	if(grid[y+1][x] == '.'){ans++;}
	if(grid[y-1][x] == '.'){ans++;}
	if(grid[y][x+1] == '.'){ans++;}
	if(grid[y][x-1] == '.'){ans++;}
	return ans;
}
void flood(vector<vector<bool>>& visit, int y, int x, vector<vector<char>> &grid){
	if(grid[y][x] == '#' && visit[y][x] == false){
		visit[y][x] = true;
		area++;
		perimeter += edge(grid, y, x);
		flood(visit, y+1, x, grid);
		flood(visit, y-1, x, grid);
		flood(visit, y, x-1, grid);
		flood(visit, y, x+1, grid);
	}
}
int main() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	int n; cin>>n;
	vector<vector<char>> grid(n+2, vector<char>(n+2, '.'));
	vector<vector<bool>> visit(n+2, vector<bool>(n+2, false));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>grid[i+1][j+1];
			
		}
	}
	pair<int,int> ans = {0,0};
	for(int i=1; i<grid.size()-1; i++){
		for(int j=1; j<grid[i].size()-1; j++){
			if(grid[i][j] == '#'){
				area = 0;
				perimeter = 0;
				flood(visit, i, j, grid);
				if(area > ans.first){
					ans.first = area;
					ans.second = perimeter;
				}else if(area == ans.first && perimeter < ans.second){
					ans.second = perimeter;
					ans.first = area;
				}
			}
		}
	}
	cout<<ans.first<<" "<<ans.second;
}
