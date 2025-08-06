#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
    while(t--){
        int n, s; cin>>n>>s;
        vector<int> x(n);
        for(int i=0; i<n; i++){
            cin>>x[i];
        }
        sort(x.begin(), x.end());
        int ans = min(abs(x[n-1] - s) + abs(x[n-1] - x[0]), abs(x[0] - s) + abs(x[0] - x[n-1]));
        cout<<ans<<endl;
    }
}
