#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct custom{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    }
};
int main() {
	int n; cin>>n;
    vector<pair<int,int>> cows(n);
    for(int i=0; i<n; i++){
        cin>>cows[i].first>>cows[i].second;
    }
    sort(cows.begin(), cows.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, custom> ending;
    int ans = -1;
    int pos = 0;
    int time = 0;
    while(pos < n){
        time = cows[pos].first;
        //add first cow to time and pq
        //remove last cow from pq
        while(!ending.empty() && ending.top().second < time){
            ending.pop();
        }
        ending.push(cows[pos]);  
        pos++;   

        ans = max(ans,(int)ending.size());

    }
    cout<<ans<<endl;

}
