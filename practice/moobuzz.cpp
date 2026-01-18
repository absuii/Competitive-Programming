#include <bits/stdc++.h>
using namespace std;
int pos(int mid){
    int extra = mid % 15;
    if(extra == 0) extra = 0;
    else if(extra == 1) extra = 1;
    else if(extra == 2) extra = 2;
    else if(extra == 3) extra = 2;
    else if(extra == 4) extra = 3;
    else if(extra == 5) extra = 3;
    else if(extra == 6) extra = 3; 
    else if(extra == 7) extra = 4;
    else if(extra == 8) extra = 5;
    else if(extra == 9) extra = 5;
    else if(extra == 10) extra = 5;
    else if(extra == 11) extra = 6;
    else if(extra == 12) extra = 6;
    else if(extra == 13) extra = 7;
    else if(extra == 14) extra = 8;
    int times = mid / 15;
    times *= 8;
    
    return times + extra;
}
int main() {
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
	int n; cin>>n;
    int low =0; int high = 2000000000;
    int mid = low + (high-low)/2;
    int ans = INT_MAX;
    while(high > low){
        mid = low + (high-low)/2;
        int p = pos(mid);
        if(p==n){
            ans = mid;
            low = high;
        }else if(p>n){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }   
    cout<<ans<<endl;
}
