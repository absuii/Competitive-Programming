#include <bits/stdc++.h>
using namespace std;
bool between(int a, pair<int,int> b){
    if(b.first<= a && b.second >= a) return true;
    return false;
}
struct CompareBySecond {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second; 
    }
};

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
	int c, n; cin>>c>>n;
    priority_queue<int, vector<int>, greater<int>> chickens;
    for(int i=0; i<c; i++){
        int a; cin>>a;
        chickens.push(a);
    }
   priority_queue<pair<int,int>, vector<pair<int,int>>, CompareBySecond> cows;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        cows.push({a,b});
    }
    int ans = 0;
    while(!chickens.empty() && !cows.empty()){
        if(between(chickens.top(), cows.top())){
            ans++;
            chickens.pop();
            cows.pop();
        }else{
            if(cows.top().second < chickens.top()){
                cows.pop();
            }else{
                chickens.pop();
            }
        }
    }
    cout<<ans<<endl;
}
