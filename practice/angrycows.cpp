#include <bits/stdc++.h>
using namespace std;
double left(set<int>& cows, double power, double point) {
    if(power <= 0) return point;
    auto it = cows.lower_bound(point - power);
    if(it == cows.begin()) return -1;
    --it;
    if(*it >= point - power && *it < point) {
        return left(cows, power - 1, *it);
    }
    return point;
}

double right(set<int>& cows, double power, double point) {
    if(power <= 0) return point;
    auto it = cows.upper_bound(point);
    if(it == cows.end()) return 10e10;
    if(*it <= point + power && *it > point) {
        return right(cows, power - 1, *it);
    }
    return point;
}
int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
	int n; cin>>n;
    set<int> cows;
    for(int i=0; i<n; i++){int a;cin>>a;cows.insert(a);}
    double droppingPoint = 0; double dPowerTemp = 0;
    for(auto i = cows.begin(); i!=cows.end(); i++){
        if(i!=cows.begin()){
            if(*i - *prev(i) > dPowerTemp){
                dPowerTemp = *i - *prev(i);
                droppingPoint = (*i + *prev(i))/2;
            }
        }
    }
    double low = 0; double high = 10e9; double mid = (((double)(high-low))/2) + low;
    double ans = 10e9;
    int count = 0;
    while(count<100){
        count++;
        mid = (((double)(high-low))/2) + low;
        bool works = left(cows, mid, droppingPoint) <= *cows.begin() && right(cows, mid, droppingPoint) >= *prev(cows.end());

        if(works){
            high = mid;
            ans = min(ans,mid);
        }else{
            low = mid;
        }
    }

    


    cout<<fixed<<setprecision(1)<<ans;
}
