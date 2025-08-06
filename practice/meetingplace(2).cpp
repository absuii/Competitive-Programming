#include <bits/stdc++.h>
using namespace std;
#define pos first
#define speed second
const double EPS = 10e-7;
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
    double ans = numeric_limits<double>::max();
    double low = 0;
    double high = 10e9; double mid = (low+high) /2;
    int count = 0;
    while(count<100){
        count++;
        
        double current = -numeric_limits<double>::max();
        double prev = -numeric_limits<double>::max();
        double fut = -numeric_limits<double>::max();
        mid = ( high + low ) /2;
        for(int i=0; i<n; i++){
            current=max(current, time(cows[i].pos, cows[i].speed, mid));
            fut=max(fut, time(cows[i].pos, cows[i].speed, mid+EPS));
            prev=max(prev, time(cows[i].pos, cows[i].speed, mid-EPS));
        }

        ans = min(ans, current);
        ans  = min(ans, prev);
        ans = min(fut, ans);
        if(fut < prev){
            low = mid+0.00000001;
        }else{
            high = mid - 0.00000001;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;



}
