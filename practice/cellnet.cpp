#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q; cin>>n>>q;
    vector<pair<int,bool>> buildings(n+q);
    vector<int> left(n+q);
    vector<int> right(n+q);
    vector<int>count(n+q);
    for(int i=0; i<n; i++){
        cin>>buildings[i].first;
        buildings[i].second = true;
    }
    //true means it is a city
    for(int i=n; i<n+q; i++){
        cin>>buildings[i].first;
        buildings[i].second  = false;
    }
    //false means it is a tower
    sort(buildings.begin(), buildings.end());
    //find first tower
    int first = 0;
    while(first!=n+q && buildings[first].second){
        first++;
    }

    for(int i=first; i<n+q; i++){
        if(buildings[i].second == true){
            left[i] = abs(buildings[first].first - buildings[i].first);
            count[i]++;
        }else{
            first = i;
        }
    }
    first = n+q-1;
    while(first!=0 && buildings[first].second){
        first--;
    }

    for(int i=first; i>=0; i--){
        if(buildings[i].second == true){
            right[i] = abs(buildings[first].first - buildings[i].first);
            count[i]++;
        }else{
            first = i;
        }
    }
    vector<int> center(n+q);
    for(int i=0; i<n+q; i++){
        if(count[i] != 1){

        center[i] = min(left[i], right[i]);
        }else{
            center[i] = max(left[i], right[i]);
        }
    }    
    cout<<*max_element(center.begin(), center.end());
}
