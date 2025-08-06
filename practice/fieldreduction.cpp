#include <bits/stdc++.h>
using namespace std;
int maxY(vector<pair<int,int>> cows,int a,int b){
	int ans = 0;
	for(int i=0+a; i<cows.size()-b; i++){
		ans=max(ans,cows[i].second);
	}
	return ans;
}
int minY(vector<pair<int,int>> cows,int a,int b){
	int ans = 1000000000;
	for(int i=0+a; i<cows.size()-b; i++){
		ans=min(ans,cows[i].second);
	}
	return ans;
}
int minX(vector<pair<int,int>> cows,int a,int b){
	int ans = 1000000000;
	for(int i=0+a; i<cows.size()-b; i++){
		ans=min(ans,cows[i].first);
	}
	return ans;
}
int maxX(vector<pair<int,int>> cows,int a,int b){
	int ans = 0;
	for(int i=0+a; i<cows.size()-b; i++){
		ans=max(ans,cows[i].first);
	}
	return ans;
}
bool customX(pair<int,int> a, pair<int,int> b){
	{
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
}
bool customY(pair<int,int> a, pair<int,int> b){
	{
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
}

int main() {
	int ans=2147483647;
	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);
	int n; cin>>n;
	vector<pair<int,int>> cows(n);

	for(int i=0; i<n; i++){
		cin>>cows[i].first>>cows[i].second;
	}
	vector<pair<int,int>> x = cows;
	vector<pair<int,int>> y = cows;
	sort(x.begin(),x.end(), customX);
	sort(y.begin(),y.end(), customY);
	ans = min(ans, (x.back().first-x[1].first) * (maxY(x,1,0) - minY(x,1,0)));
	ans = min(ans, (x[n-2].first - x[0].first) * (maxY(x,0,1) - minY(x,0,1)));
	ans = min(ans, (y.back().second-y[1].second) * (maxX(y,1,0) - minX(y,1,0)));
	ans = min(ans, (y[n-2].second-y[0].second) * (maxX(y,0,1) - minX(y,0,1)));
	cout<<ans;
	
}
