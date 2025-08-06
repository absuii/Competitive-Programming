#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, q; cin>>n>>k>>q;
    vector<int> recipes(200002);
    vector<bool> rec(recipes.size());
    vector<int> aboveK(rec.size());
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        recipes[a]++;
        recipes[b+1]--;
    }
    for(int i=1; i<200002; i++){
        recipes[i]+=recipes[i-1];
        if(recipes[i]>=k){
            rec[i] = true;
        }
        if(rec[i]){
            aboveK[i]++;
        }
        aboveK[i]+=aboveK[i-1];
    }

    for(int i=0; i<q; i++){
        int a,b;cin>>a>>b;
        int ans = aboveK[b] - aboveK[a-1];
        cout<<ans<<endl;
    }
}
