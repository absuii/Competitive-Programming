#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
bool simulate(vector<pair<ll,ll>>& patches, ll dis, ll n, ll m){
    ll ans = 1;
    ll currentPatch = 0;
    ll currentPos = patches[0].first;
    while(ans < n){
        ll nextPos = currentPos + dis;
        while(currentPatch < m && nextPos > patches[currentPatch].second){
            currentPatch++;
        }
        if(currentPatch >= m) break;
        if(nextPos < patches[currentPatch].first){
            currentPos = patches[currentPatch].first;
        } else {
            currentPos = nextPos;
        }
        ans++;
    }
    return ans >= n;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    //binary search for the min distance between cows
    // so we get O(log N)
    //next, we must simulate in O(N log N) or O(N)
    //sort every patch
    //Iterate through every patch
    //Add a cow to lowest possible position
    //add a cow to MID + current
    // if it falls out of range of current, repeat until it doesnt
    //if there are extra cows, lower mid
    //else increase mid
	ll n, m; cin>>n>>m;
    vector<pair<ll,ll>> patches(m);
    for(ll i=0; i<m; i++){cin>>patches[i].first>>patches[i].second;}
    sort(patches.begin(), patches.end());
    ll low = 1; ll high = 1e18; ll mid = low + (high -low)/2; ll ans = 1;
    while(high >= low){
        mid = low + (high -low)/2;
        if(simulate(patches, mid, n, m)){
            ans = max(mid, ans);
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout<<ans;
}
