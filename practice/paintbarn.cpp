#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cows(1001, vector<int>(1001));
int main() {
    freopen("paintbarn.in","r", stdin);
    freopen("paintbarn.out", "w", stdout);
	int n, k; cin>>n>>k;
    for(int j=0; j<n; j++){
        int x1, x2, y1, y2; cin>>x1>>y1>>x2>>y2;
        for(int i = y1; i<y2; i++){
            cows[i+1][x1+1]++; cows[i+1][x2+1]--;
        }
    }
    int ans = 0;
    
    for(int i =1; i<cows.size(); i++){
        for(int j=1; j<cows[i].size(); j++){
            cows[i][j] = cows[i][j] + cows[i][j-1];
        }
    }
   
    for(int i =1; i<cows.size(); i++){
        for(int j=1; j<cows[i].size(); j++){
            if(cows[i][j]== k){
                ans++;
            }
        }
    }

    cout<<ans;

    
}
