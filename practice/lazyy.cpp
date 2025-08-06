#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
	int n, k; cin>>n>>k;
    vector<vector<int>> cows(n+1, vector<int>(n+1));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin>>cows[i][j];
            cows[i][j]+=cows[i][j-1];
        }
    }
    int answer = INT_MIN;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            int ans = 0;
            for(int a = i-k; a<=i+k; a++){
                if(a >= 0 && a<=n){
                    int dist = k - abs(a - i);
                    int left = j - dist;
                    int right = j + dist;


				    left = max(1, min(n, left));
				    right = max(1, min(n, right));

                    ans+= cows[a][right] - cows[a][left-1];
                    
                }
            }
            answer = max(ans, answer);
        }
    }
    cout<<answer;
}
