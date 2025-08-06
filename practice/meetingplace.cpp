#include <bits/stdc++.h>
using namespace std;
#define pos first
#define speed second

double time(double p, double s, double t){
    return abs(t-p)/s;
}

int main() {
    //sort meeting places of friends
    //binary search the point where everyone should meet
    // if the max time for cows[i] to reach place > ans
    // if the max time for cows[i] to reach place < ans
    //find which direction it increases and use that in binary search condition
	// we arent not finding min time
    //we are finding the min maximum time for one cow
    double n; cin>>n;
    vector<pair<double,double>> cows((int)n);
    for(int i=0; i<n; i++){
        cin>>cows[i].pos;
    }
    for(int i=0; i<n; i++){
        cin>>cows[i].speed;
    }
    double ans= INT_MAX;
    double low = 0;
    double high = 10e9; double mid = (low+high) /2;
    int count = 0;
    while(count<1000){
        count++;
        double current = INT_MIN;
        mid = ( high - low ) /2 + low;
        for(int i=0; i<n; i++){
            current=max(current, time(cows[i].pos, cows[i].speed, mid));
        }
        double prev = INT_MIN;
        for(int i=0; i<n; i++){
            prev=max(prev, time(cows[i].pos, cows[i].speed, mid-0.00000000001));
        }
        double fut = INT_MIN;
        for(int i=0; i<n; i++){
            fut=max(fut, time(cows[i].pos, cows[i].speed, mid+0.00000000001));
        }
        ans = min(ans, current);
        if(fut < prev){
            low = mid+0.00000000001;
        }else{
            high = mid - 0.00000000001;
        }
    }
    cout<<ans;


}
