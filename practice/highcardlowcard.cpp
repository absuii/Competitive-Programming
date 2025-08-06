#include <bits/stdc++.h>
using namespace std;
set<int> bessie;
vector<int> cows;
set<int> high;
set<int> low;
vector<bool> total;
int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n; cin>>n;
    cows.resize(n);
    total.resize(2*n);
    for(int i=0; i<n/2; i++){
        cin>>cows[i];
        high.insert(cows[i]);
        total[cows[i]] = true;
    }
    for(int i=0; i<n/2; i++){
        cin>>cows[i + (n/2)];
        low.insert(cows[i + (n/2)]);
        total[cows[i+ n/2]] = true;
    }
    for(int i=1; i<2*n+1; i++){
        if(!total[i]){
            bessie.insert(i);
        }
    }

    int ans = 0;
    for(int i:low){
        auto it = bessie.lower_bound(i);
        if(it != bessie.begin()){
            --it;
            bessie.erase(it);
            ans++;
        }

    }
     for(auto a = high.rbegin(); a != high.rend(); ++a){
        auto it = bessie.upper_bound(*a);
        if(it!=bessie.end()){
            if(*it > *a){
                bessie.erase(it);
                ans++;
            }
        }
    }
   
   
    cout<<ans;
}