#include <bits/stdc++.h>
using namespace std;
pair<int,int> getMax(vector<vector<int>>& nums){
    int m = -3;
    int im;
    int jm;
    for(int i=0; i<nums.size(); i++){
        for(int j=0;j<nums[i].size(); j++){
            m = max(m, nums[i][j]);
            if(m == nums[i][j]){
                im = i;
                jm = j;
            }
        }
    }
    return {im, jm};
}
void col(vector<vector<int>>& nums, int c, int a){
    for(int i=0; i<nums.size(); i++){
        nums[i][c]+=a;
    }
}
void row(vector<vector<int>>& nums, int c, int a){
    for(int i=0; i<nums[c].size(); i++){
        if(true){
            nums[c][i]+=a;
        }
    }
}
int getMatrixMax(const vector<vector<int>>& nums) {
    int m = INT_MIN;
    for(const auto& row : nums) {
        for(int val : row) {
            m = max(m, val);
        }
    }
    return m;
}
int main() {
	int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        vector<vector<int>> nums(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>nums[i][j];
            }
        }
        int answer = INT_MAX;

 
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                vector<vector<int>> temp = nums;
                row(temp, r, -1);
                col(temp, c, -1);
                temp[r][c] += 1; // 
                answer = min(answer, getMatrixMax(temp));
            }
        }

        cout << answer << '\n';
    }
}
