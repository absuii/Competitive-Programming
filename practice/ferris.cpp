#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin>>n>>x; 
    vector<int> cows(n);
    for(int i=0; i<n; i++){cin>>cows[i];}
    sort(cows.begin(), cows.end());
    int high = n-1;
    int low = 0;
    int ans = 0;
    while(high >=low){
        if(high == low){
            ans++;
            high--;
            low++;
        }else{
            if(cows[high] >= x || cows[high] + cows[low] > x){
                ans++;
                high--;
            }else{
                ans++;
                low++;
                high--;
            }
        }
    }
    cout<<ans;
}
