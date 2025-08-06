#include <bits/stdc++.h>
using namespace std;
void update(long long currentPos, vector<pair<long long,long long>>& fields){
    long long i = fields.size()-1;
    while(i >=0 && fields[i].first <= currentPos){
        fields.pop_back();
        i--;
    }
}

bool customComparator(pair<long long, long long> one, pair<long long,long long> two){
    if(one.second == two.second){
        return one.first > two.first;
    }
    return one.second < two.second;
}

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
	//sort all polong longs by weight
    //stay as long as possible in weight[end-1] (last one)
    //then once we've crossed it, update to the next max
    long long l,n, bessieSpeed, johnSpeed; cin>>l>>n>>johnSpeed>>bessieSpeed;
    vector<pair<long long,long long>> rests(n);
    for(long long i=0; i<n; i++){
        cin>>rests[i].first>>rests[i].second;
    }
    sort(rests.begin(), rests.end(), customComparator);
    long long ans = 0; long long pos = 0;
    while(!rests.empty()){
        long long timeForBessieToReach = (rests[rests.size()-1].first - pos) * bessieSpeed;
        long long timeForJohnToReach = (rests[rests.size()-1].first - pos) * johnSpeed;
        ans+= (timeForJohnToReach - timeForBessieToReach) * rests[rests.size()-1].second;
        pos = rests[rests.size()-1].first;
        update(pos, rests);
    }
    cout<<ans<<endl;
}
