#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k; cin>>n>>k;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    int ans = INT_MAX;
    int low = 0; int high = 1000000000;
    int mid = low + (high-low)/2;
    int count = 0;
    while(count<100){
        count++;
        mid = low + (high-low)/2;
        int subsets = 1;
        int sum=0;
        for(int i=0; i<n; i++){
            if(sum + p[i] <= mid){
                sum+=p[i];
            }else{
                subsets++;
                sum = p[i];
            }
        }
        if(subsets == k){
            ans = min(mid, ans);
        }
        if(subsets > k){
            low = mid;
        }else{
            high = mid;
        }

    }
    cout<<ans;
}
