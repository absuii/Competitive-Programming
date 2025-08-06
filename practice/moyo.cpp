#include <bits/stdc++.h>
using namespace std;

void gravity(vector<vector<int>>& sky, int i, int j){
    if(i==sky.size()-1) return;
    if(sky[i+1][j] == 0){
        sky[i+1][j] = sky[i][j];
        sky[i][j] = 0;
        gravity(sky, i+1, j);
    }
}
void flood(vector<vector<bool>>& visited, vector<vector<int>>& sky, int i, int j, int parentI, int parentJ, vector<vector<shared_ptr<int>>>& groups){
    if(visited[i][j] || sky[i][j] == 0|| sky[i][j] !=sky[parentI][parentJ]) return;
    visited[i][j] = true;
    if (!groups[parentI][parentJ]){
        groups[parentI][parentJ] = make_shared<int>(0);
    }
    groups[i][j] = groups[parentI][parentJ];
    (*groups[i][j])++;
    if(i!=0){
        flood(visited,sky,i-1,j,i,j, groups);
    }
    if(i!=sky.size()-1){
        flood(visited,sky,i+1,j,i,j, groups);
    }
    if(j!=0){
        flood(visited,sky,i,j-1,i,j, groups);
    }   
    if(j!=9){
        flood(visited,sky,i,j+1,i,j, groups);
    }

}
int main() {
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
	int n,k; cin>>n>>k;
    vector<vector<int>> sky(n, vector<int>(10));
for(int i = 0; i < n; i++) {
    string row;
    cin >> row; 
    for(int j = 0; j < 10; j++) {
        sky[i][j] = row[j] - '0'; 
    }
}
    for(int a=0; a<100; a++){
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<10; j++){
                gravity(sky, i,j);
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(10));
        vector<vector<shared_ptr<int>>> groups(n, vector<shared_ptr<int>>(10));
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                if(!visited[i][j] && sky[i][j]!=0){
                    flood(visited, sky, i, j, i, j, groups);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<10; j++){
                if (groups[i][j] && *groups[i][j] >= k) {
                    sky[i][j] = 0;
                }

            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            cout<<sky[i][j];
        }
        cout<<endl;
    }
}
