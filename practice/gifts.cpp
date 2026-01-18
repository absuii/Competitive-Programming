#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
    vector<vector<int>> cows(n, vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cows[i][j];
        }
    }
    vector<bool> used(n+1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!used[cows[i][j]]){
                cout<<cows[i][j]<<endl;
                used[cows[i][j]] = true;
                break;
            }
        }
    }
}
