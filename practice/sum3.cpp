// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x; cin>>n>>x;
    vector<pair<int,int>> cows(n);
    for(int i=0; i<n; i++){
        cin>>cows[i].first;
        cows[i].second = i;
    }
    bool done = false;
    //n^2 solution
    // first loop, iterate over all numbers to find target
    //2nd loop find the 2 numbers using 2 pointers that will sum with target
    for(int target = 0; target<n; target++){
        int first = 0; int last = n-1;
    while(cows[first].first + cows[last].first + cows[target].first!=x && last > first){
            if(first!=target && last!=target){
               int sum = cows[first].first + cows[last].first + cows[target].first;
            if(sum > x){
                last--;
            }else if(sum < x){
                first++;
            }else if(sum == x){
                break;
            }
        }
        
    }
    if(first < last ){
        cout<<cows[first].second +1 <<" "<< cows[last].second +1<< " "<<target + 1;
        done = true;
        break;
    }
    
    }
    if(!done){
        cout<<"IMPOSSIBLE";
    }
}
