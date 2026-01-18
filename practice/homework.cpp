#include <bits/stdc++.h>
using namespace std;
int sum(vector<int>& p, int point){
    return p[p.size()-1] - p[point];
}
int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

	int n; cin>>n;
    vector<int> cows(n);
    for(int i=0; i<n; i++){cin>>cows[i];}
    vector<int> p(n+1);
    vector<int> m(n);
    for(int i=1; i<=n; i++){
        p[i] = p[i-1] + cows[i-1];
    }
    m[n-1] = cows[n-1];
    for(int i=n-2; i>=0; i--){
        m[i] = min(m[i+1],cows[i]);
    }
    pair<double,vector<int>> ans;
    for(int i=0; i<n; i++){
        double average = double(sum(p,i) - m[i])/double(n-1-i);
        if(average > ans.first){
            ans.first = average;
            ans.second = {i};
        }else if(average == ans.first){
            ans.second.push_back(i);
        }
    }
    for(int i=0; i<ans.second.size(); i++){
        if(ans.second[i]!=0){

            cout<<ans.second[i];
            if(i!=ans.second.size()-1){
                cout<<" ";
            }
        }
    }

}
