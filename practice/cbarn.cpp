#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cows;
int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
	int n; cin>>n;
    cows.resize(n);
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
        for(int j=0; j<nums[i]; j++){
            cows[i].push_back(0);
        }
    }
    for(int a=0; a<n; a++){
        for(int i=0; i<n; i++){
            if(nums[i] > 0 && nums[(i+1)%n] == 0){
                nums[i]--;
                int num = cows[i][nums[i]];
                cows[i].resize(cows[i].size()-1);
                nums[(i+1)%n]++;
                cows[(i+1)%n].push_back(num+1);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans+=cows[i][0] * cows[i][0];
    }
    cout<<ans;
}
