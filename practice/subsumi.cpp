// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int first = 0; int last = 0; int pf = -1; int pl = -1;
    int ans = 0; int sum = a[first];
    while(last < n && first < n){
        pf = first;
        pl = last;
        if(sum == x){
            ans++;
            sum-=a[first];
            first++;
        } else if (sum < x){
            if(last != n-1){
                last++;
                sum+=a[last];
            }
            
        }else if(sum > x){
            sum-=a[first];
            first++;
        }
        if(pf == first && pl == last){
            break;
        }
        
    }
    cout<<ans;
}
