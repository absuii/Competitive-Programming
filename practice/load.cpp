#include <bits/stdc++.h>
using namespace std;
void split(vector<int>& quads, vector<pair<int,int>>& cows, int x, int y){
    for(int i=0; i<cows.size(); i++){
        if(cows[i].first > x){
            if(cows[i].second > y){
                quads[0]++;
            }else{
                quads[3]++;
            }
        }else{
            if(cows[i].second > y){
                quads[1]++;
            }else{
                quads[2]++;
            }
        }
    }
}
int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n; cin>>n;
    vector<pair<int,int>> cows(n);
    for(int i=0; i<n; i++){
        cin>>cows[i].first>>cows[i].second;
    }
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        vector<int> quads(4);
        split(quads, cows, cows[i].first-1, cows[i].second-1);
        ans=min(ans, *max_element(quads.begin(), quads.end()));
    }
    cout<<ans;
}
