#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n; cin>>n;
    vector<pair<long long,long long>> tasks(n);
    for(long long i=0; i<n; i++){cin>>tasks[i].first>>tasks[i].second;}
    sort(tasks.begin(), tasks.end());
    long long ans = 0; long long t = 0;
    for(long long i=0; i<n; i++){
        t+=tasks[i].first;
        ans += tasks[i].second - t;
    }
    cout<<ans;
}
