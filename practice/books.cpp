#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n, t; cin>>n>>t;
    vector<ll> books(n);
    for(ll i=0; i<n; i++){
        cin>>books[i];
    }
    int start = 0;
    int end = 0;
    int sum = books[0];
    int ans = 0;
    while(end < n-1 && start < n-1){
        if(end!=n-1 && sum + books[end+1]<= t){
            end++;
            sum+=books[end];
        }else {
            if (start < n)
                sum -= books[start];
            start++;
        }
        if(sum <= t){
            ans = max(end-start+1,ans);
        }
        
    }
    if(n==1){
        if(sum <= t){
            ans = 1;
        }else{
            ans = 0;
        }
    }
    cout<<ans;
}
