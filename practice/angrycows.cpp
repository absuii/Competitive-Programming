#include <bits/stdc++.h>
using namespace std;

int simulate(vector<int>& cows, int r){
    int ans = 1;
    int lastCow = 0;
    for(int i=0; i<cows.size(); i++){
        if(cows[i] - cows[lastCow] > 2 * r){
            ans++;
            lastCow = i;
        }
    }
    return ans;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
	int n, k; cin>>n>>k;
    vector<int> cows(n);
    for(int i=0; i<n; i++){
        cin>>cows[i];
    }
    sort(cows.begin(),cows.end());
    int low = 0; int high = 10e9; int mid = low + (high-low)/2; int ans = 10e9;
    while(low < high){
        mid = low + (high-low)/2;
        int requiredCows = simulate(cows, mid);
        if(requiredCows <= k){ // less cows needed, decrease r
            high = mid -1;
            ans = min(ans, mid);
        }else{ // too many cows needed, increase r
            low = mid+1;
        }
    }
    cout<<ans;
}
