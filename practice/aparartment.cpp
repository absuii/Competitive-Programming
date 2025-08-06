#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k; cin>>n>>m>>k;
    vector<int> cows(n);
    vector<int> apart(m);
    map<int,int> apartLeft;
    map<int,bool> cowsLeft;
    set<int> remaining;
    for(int i=0; i<n; i++){cin>>cows[i];}
    for(int i=0; i<m; i++){cin>>apart[i]; apartLeft[apart[i]]++; remaining.insert(apart[i]);}
    sort(cows.begin(), cows.end());
    for(int i=0; i<n; i++){cowsLeft[cows[i]] = false;}
    sort(apart.begin(), apart.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        auto it = remaining.lower_bound(cows[i]);
        if(it != remaining.begin()){
            --it;
            if(apartLeft[*it]>0 && abs(*it - cows[i]) <= k){
                ans++;
                cowsLeft[cows[i]] = true;
                apartLeft[*it]--;
                if(apartLeft[*it] == 0){
                    remaining.erase(it);
                }
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        if(!cowsLeft[cows[i]]){

            auto it = remaining.upper_bound(cows[i]);
            if(it != remaining.begin()){
                --it;
                if(apartLeft[*it]>0 && abs(*it - cows[i]) <= k){
                    ans++;
                    cowsLeft[cows[i]] = true;
                    apartLeft[*it]--;
                    if(apartLeft[*it] == 0){
                        remaining.erase(it);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
