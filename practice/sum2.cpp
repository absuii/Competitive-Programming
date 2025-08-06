#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin>>n>>x;
    vector<pair<int,int>> cows(n);
    for(int i=0; i<n; i++){
        cin>>cows[i].first;
        cows[i].second = i;
    }
    sort(cows.begin(), cows.end());
    int first = 0; int last = n-1;
    while(cows[first].first + cows[last].first!=x && last > first){
        int sum = cows[first].first + cows[last].first;
        if(sum > x){
            last--;
        }else if(sum < x){
            first++;
        }else if(sum == x){
            break;
        }
    }
    if(first >= last ){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<cows[first].second +1 <<" "<< cows[last].second +1;
    }
}
