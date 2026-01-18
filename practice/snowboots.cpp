#include <bits/stdc++.h>
using namespace std;

int run(pair<int,int> boot, int current, vector<int>& depth){
    int limit = min(int(depth.size() - 1), current + boot.second);
    for(int i=limit; i>current; i--){
        if(depth[i]<=boot.first){
            return i;
        }
    }
    return current;
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
	int n, b; cin>>n>>b;
    vector<int> depth(n);
    for(int i=0; i<n; i++){
        cin>>depth[i];
    }
    vector<pair<int,int>> boots(b);
    for(int i=0; i<b; i++){
        cin>>boots[i].first>>boots[i].second;
    }
    int pos = 0;
    int currentBoot = 0;
    int ans = 0;
    
    while(pos != n - 1){
        int newPos = run(boots[currentBoot], pos, depth);  
        if(newPos == pos){
            currentBoot++;
            ans++;
        } else {
            pos = newPos;
        }
    }
    cout << ans << endl;
}
