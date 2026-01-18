#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t; cin>>n>>t; int a = n;
    int start = 0; int end = n-1; int ans = INT_MIN; int mid;
    while(a--){
        cout<<"? ";
        mid = (end-start)/2 + start;
        cout<<mid + 1<<" "<<end+1<<endl;
        int x; cin>>x;
        if(x > end - mid){
            end = mid-1;
        }else{
            start = mid+1;
            ans = max(mid, ans);
        }
    }
    cout<<"! "<<ans +1;
}
