
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
	//Sort the trees  by number of berries
    //Put the biggest trees in basket until either
    // if number of baskets is full - check if splitting the biggest one helps - then print ans
    //else if there are leftover baskets - split the biggest ones until they are full - then print ans
    int n, k; cin>>n>>k;
    vector<int> berries(n);
    for(int i=0; i<n; i++){
        cin>>berries[i];
    }
    sort(berries.begin(), berries.end());
    vector<int> baskets;
    int a = n-1;
    while(a>=0 && baskets.size() < k){
        baskets.push_back(berries[a]);
        a--;
    }
    if(baskets.size() == k){
        sort(baskets.rbegin(), baskets.rend());
        while(baskets[0]/2 > baskets[baskets.size()-1]){
            int temp = baskets[0];
            baskets[0]/=2;
            baskets[baskets.size()-1] = (temp + 1)/2;
            sort(baskets.rbegin(), baskets.rend());
        }   
    }else{
        while(baskets.size() < k){
            int temp = baskets[0] =1;
            baskets[0] = baskets[0]/2;
            baskets.push_back(temp/2);
            sort(baskets.rbegin(), baskets.rend());
        }
    }
    sort(baskets.begin(), baskets.end());
    int ans = 0;
    for(int i=0; i<baskets.size()/2; i++){
        ans+=baskets[i];
    }
    cout<<ans<<endl;
}
